//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_IP 20 // maximum length of an IP address
#define MAX_BUF 1024 // maximum buffer length

int main() {
    char ip[MAX_IP]; // array to hold the IP address
    float delay = 0; // variable to hold the delay value
    float jitter = 0; // variable to hold the jitter value
    float packet_loss = 0; // variable to hold the packet loss value
    char cmd[MAX_BUF]; // buffer to hold the command string
    FILE *fp; // file pointer
    char *line = NULL; // pointer to line in file
    size_t len = 0; // length of line
    ssize_t read; // number of bytes read

    while(1) {
        printf("Enter IP address to monitor: ");
        fflush(stdout);
        fgets(ip, MAX_IP, stdin); // get IP address from user input
        if(ip[strlen(ip)-1] == '\n') ip[strlen(ip)-1] = '\0'; // remove newline character
        printf("Monitoring network quality of %s...\n", ip);

        // build command string for ping
        sprintf(cmd, "ping -c 10 %s | tail -3 | awk '{print $4}' | cut -d '/' -f 2,3 | sed 's/^/delay=/g; s/\\/.*ms, jitter=/jitter=/g; s/\\/.*% loss//g'", ip);

        fp = popen(cmd, "r"); // execute command and open pipe to capture output
        if(fp == NULL) {
            printf("Error: failed to execute ping command\n");
            continue;
        }

        // read the output from the ping command
        while((read = getline(&line, &len, fp)) != -1) {
            if(strncmp(line, "delay=", 6) == 0) {
                sscanf(line, "delay=%f, jitter=%f", &delay, &jitter);
            } else if(strncmp(line, "jitter=", 7) == 0) {
                sscanf(line, "jitter=%f", &jitter);
            } else if(strncmp(line, "packet loss", 11) == 0) {
                sscanf(line, "%f", &packet_loss);
            }
        }

        pclose(fp); // close pipe to free resources

        // display the results of the ping command
        printf("Delay: %.2f ms\n", delay);
        printf("Jitter: %.2f ms\n", jitter);
        printf("Packet Loss: %.2f%%\n", packet_loss);

        // check the quality of the network connection based on the QoS values
        if(delay > 100 || jitter > 50 || packet_loss > 5) {
            printf("Warning: network quality is poor!\n");
        } else if(delay > 50 || jitter > 20 || packet_loss > 1) {
            printf("Network quality is fair.\n");
        } else {
            printf("Network quality is excellent!\n");
        }

        // wait for 10 seconds before monitoring again
        sleep(10);
    }

    return 0;
}