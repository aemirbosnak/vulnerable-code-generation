//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char *log = "Oct 23 16:35:31 localhost sshd[28245]: Invalid user root from 192.168.1.1";
    char timestamp[25], hostname[50], process[50], message[100], ip[15], username[50];
    int pid, i = 0;

    while(log[i] != ' ') {
        timestamp[i] = log[i];
        i++;
    }
    timestamp[i] = '\0';
    i++;

    int j = 0;
    while(log[i] != ' ') {
        hostname[j] = log[i];
        i++;
        j++;
    }
    hostname[j] = '\0';
    i++;

    j = 0;
    while(log[i] != ' ') {
        process[j] = log[i];
        i++;
        j++;
    }
    process[j] = '\0';
    i++;

    j = 0;
    while(log[i] != '[') {
        message[j] = log[i];
        i++;
        j++;
    }
    message[j] = '\0';
    i++;

    j = 0;
    while(log[i] != ']') {
        username[j] = log[i];
        i++;
        j++;
    }
    username[j] = '\0';
    i+=2;

    j = 0;
    while(log[i] != '\0') {
        ip[j] = log[i];
        i++;
        j++;
    }
    ip[j] = '\0';

    // Output
    printf("Timestamp: %s\n", timestamp);
    printf("Hostname: %s\n", hostname);
    printf("Process: %s\n", process);
    printf("Message: %s\n", message);
    printf("Username: %s\n", username);
    printf("IP: %s\n", ip);

    return 0;
}