#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

char buf[MAX_LINE];

void edit() {
    system("clear");
    printf("Simple Text Editor\n");
    printf("=================\n\n");

    while (1) {
        printf("> ");
        fgets(buf, sizeof(buf), stdin);
        char* cmd = strtok(buf, " \n");

        if (!strcmp(cmd, "save")) {
            printf("Saving...\n");
            break;
        } else if (!strcmp(cmd, "quit")) {
            printf("Exiting...\n");
            return;
        } else if (!strcmp(cmd, "edit")) {
            printf("Editing...\n");
            // Vulnerable function call - Buffer Overflow
            printf("%s\n", buf);
            printf("(Overflow occurs here due to no bounds check in fscanf)\n");
        } else {
            printf("Command not found. Try again.\n");
        }
    }
}

int main() {
    edit();
    return 0;
}
