//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    system("clear");
    printf("-----------------------------------------\n");
    printf("   _..._           __..._           _...\n");
    printf("  / \_/ \_/ \__/\n");
    printf("  \__ \__ \__/\n");
    printf("   \__) \__) \__)\n");
    printf("-----------------------------------------\n");

    char str[100];
    printf("Enter a target IP address: ");
    scanf("%s", str);

    int port_num;
    printf("Enter a port number: ");
    scanf("%d", &port_num);

    time_t start_time = time(NULL);

    FILE *fp = fopen("/dev/tcp", "w");
    fprintf(fp, "CONNECT %s:%d\n", str, port_num);

    char data[1024];
    int bytes_read = read(fp, data, 1024);

    time_t end_time = time(NULL);

    printf("-----------------------------------------\n");
    printf("   _..._           __..._           _...\n");
    printf("  / \_/ \_/ \__/\n");
    printf("  \__ \__ \__/\n");
    printf("   \__) \__) \__)\n");
    printf("-----------------------------------------\n");

    printf("Target IP: %s\n", str);
    printf("Port Number: %d\n", port_num);
    printf("Time Taken: %ld seconds\n", end_time - start_time);
    printf("Data Received: %d bytes\n", bytes_read);
    printf("Data: %s\n", data);

    fclose(fp);

    return 0;
}