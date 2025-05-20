#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void edit(char *buf, int pos, int len) {
    char temp[MAX_SIZE];
    strncpy(temp, buf, pos);
    strncat(temp, "\033[1m\033[41m", len + 1);
    strcat(temp, buf + pos + len);
    strcpy(buf, temp);
}

void print_buffer(char *buf) {
    printf("\033[2J\033[H");
    printf("%s", buf);
}

int main(int argc, char *argv[]) {
    char buffer[MAX_SIZE];
    char command[10];
    int pos, len;

    memset(buffer, '\0', MAX_SIZE);
    while (1) {
        print_buffer(buffer);
        scanf("%s", command);
        if (!strcmp(command, "QUIT")) break;
        else if (!strcmp(command, "INSERT")) {
            printf("Insert what? ");
            scanf("%s", command);
            len = strlen(command);
            edit(buffer, pos, len);
        } else if (!strcmp(command, "MOVE_LEFT")) {
            if (pos > 0) pos--;
        } else if (!strcmp(command, "MOVE_RIGHT")) {
            if (pos < strlen(buffer)) pos++;
        } else if (!strcmp(command, "MOVE_UP")) {
            // Move up not implemented
        } else if (!strcmp(command, "MOVE_DOWN")) {
            // Move down not implemented
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
