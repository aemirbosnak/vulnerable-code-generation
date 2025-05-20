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
    printf("\n\nEditor\n\n");
    printf("Current text: %s\n", buf);
    printf("\nCommands:\n");
    printf("w - write\ns - save\nx - exit\nq - quit\n");

    char command[3];
    scanf("%s", command);

    if (strcmp(command, "w") == 0)
        writeFile(buf);
    else if (strcmp(command, "s") == 0)
        saveFile(buf);
    else if (strcmp(command, "x") == 0)
        exit(0);
    else if (strcmp(command, "q") == 0)
        return;

    edit();
}

void readFile(char* filename) {
    FILE* fp = fopen(filename, "r");
    fgets(buf, MAX_LINE, fp);
    fclose(fp);
}

void writeFile(char* str) {
    FILE* fp = fopen("output.txt", "w");
    fprintf(fp, "%s", str);
    fclose(fp);
}

void saveFile(char* str) {
    FILE* fp = fopen("output.txt", "w");
    fprintf(fp, "%s", str);
    fclose(fp);
    readFile("output.txt");
}

int main() {
    strcpy(buf, "Welcome to the editor!");
    edit();
    return 0;
}
