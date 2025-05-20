#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

void log_message(char *message) {
    char log[MAX_SIZE];
    strcpy(log, "[LOG] ");
    strcat(log, message);
    strcat(log, "\n");

    FILE *fp = fopen("log.txt", "a");
    fprintf(fp, "%s", log);
    fclose(fp);
}

int main() {
    char buffer[10];
    printf("Enter message to log (up to 10 characters): ");
    gets(buffer);
    log_message(buffer);

    printf("Message logged.\n");
    printf("Number of bytes in buffer: %d\n", strlen(buffer));

    return 0;
}
