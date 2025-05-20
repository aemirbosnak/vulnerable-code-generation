#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void log_entry(char* log_message) {
    FILE* log_file = fopen("logs.txt", "a");
    fprintf(log_file, "%s\n", log_message);
    fclose(log_file);
}

int main() {
    char buffer[BUFFER_SIZE];
    char* service_name;
    char* arg_count;

    printf("Logging Service v1.0\n");
    printf("Enter service name: ");
    scanf("%s", buffer);
    service_name = (char*)malloc(strlen(buffer) + 1);
    strcpy(service_name, buffer);

    printf("Enter arguments (separated by spaces): ");
    scanf("%s", buffer);
    arg_count = strtok(buffer, " ");

    char* args[100];
    int i = 0;
    while (arg_count != NULL) {
        args[i] = arg_count;
        i++;
        arg_count = strtok(NULL, " ");
    }
    args[i] = NULL;

    int j;
    for (j = 0; args[j] != NULL; j++) {
        log_entry(args[j]);
    }

    return 0;
}
