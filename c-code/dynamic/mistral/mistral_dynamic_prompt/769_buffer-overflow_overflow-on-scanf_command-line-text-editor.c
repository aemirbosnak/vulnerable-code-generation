#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char buffer[10];
char *filename = "file.txt";

void read_line() {
    printf("\033[1;1H\033[2JEnter a line: ");
    fgets(buffer, sizeof(buffer), stdin);
}

void write_line() {
    FILE *fp = fopen(filename, "a");
    fputs(buffer, fp);
    fclose(fp);
}

void load_file() {
    FILE *fp = fopen(filename, "r");
    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    fclose(fp);
}

int main() {
    char command[20];

    while (1) {
        printf("\n1: New line\n2: Save\n3: Load\n4: Exit\n");
        read_line();
        sscanf(buffer, "%d", command);

        switch (*command) {
            case 1:
                read_line();
                write_line();
                break;
            case 2:
                write_line();
                break;
            case 3:
                load_file();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
