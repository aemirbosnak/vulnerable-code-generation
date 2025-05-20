//FormAI DATASET v1.0 Category: System administration ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Bold System Administration Example Program!\n");
    printf("This program will help you manage your system processes.\n");
    printf("\n");

    while (1) {
        printf("Please enter the process name (or 'exit' to quit): ");
        char input[256];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        char output[512];
        snprintf(output, sizeof(output), "ps aux | grep %s", input);

        printf("Running command: %s\n", output);

        FILE *fp = popen(output, "r");
        if (fp == NULL) {
            printf("Error: Unable to open pipe.\n");
            continue;
        }

        printf("\n");
        printf("Results: \n");

        char buffer[1024];
        size_t length;

        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            length = strlen(buffer);
            if (buffer[length - 1] == '\n') {
                buffer[length - 1] = '\0';
            }
            printf("%s\n", buffer);
        }

        pclose(fp);

        printf("\n");
    }

    return 0;
}