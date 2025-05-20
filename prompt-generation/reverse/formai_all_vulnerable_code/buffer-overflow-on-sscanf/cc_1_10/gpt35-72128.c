//FormAI DATASET v1.0 Category: System process viewer ; Style: medieval
// Medieval style C System Process Viewer
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    printf("Welcome to the Medieval Process Viewer!\n");

    while(1) {
        system("clear");

        printf(" ===========================================\n");
        printf("| PLEASED TO PRESENT THE PROCESS TABLE OF OE! |\n");
        printf(" ===========================================\n\n");

        printf("  PID  |     NAME      |   MEMORY   |  STATUS\n");
        printf("-------|---------------|------------|---------\n");

        // Get process information
        system("ps -eo pid,comm,%mem,stat --sort=-%mem | head -n 20 | tail -n 10 > /tmp/processes");

        // Read process information from file
        char process_info[256];
        FILE* fp = fopen("/tmp/processes", "r");

        if(fp) {
            while(fgets(process_info, sizeof(process_info), fp)) {
                int pid;
                char name[20];
                float memory;
                char status;

                sscanf(process_info, "%d %s %f %c", &pid, name, &memory, &status);

                printf(" %5d | %13.13s | %6.2f%% | %c\n", pid, name, memory, status);
            }
            fclose(fp);
        } else {
            printf("Cannot read process information. Error: ");
            fflush(stdout);
            system("rm -f /tmp/processes");
            exit(EXIT_FAILURE);
        }

        printf("\nPress ENTER to refresh or type 'quit' to exit: ");
        char input[10];
        fgets(input, sizeof(input), stdin);

        if(strcmp(input, "quit\n") == 0) {
            system("rm -f /tmp/processes");
            break;
        }
    }

    printf("Farewell, brave user!\n");
    return 0;
}