#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void edit(char *filename) {
    char buffer[10];
    char file[256];
    char line[1024];

    strcpy(file, "tmp.txt");
    strcpy(buffer, "[Contents of the file]\n");

    FILE *fp = fopen(file, "w");
    fprintf(fp, "%s", buffer);
    fclose(fp);

    FILE *fp2 = fopen(file, "r");
    int counter = 0;
    while (fgets(line, 1024, fp2)) {
        if (counter == 5) {
            counter = 0;
            printf("\033[2K\r%s", line);
        }
        counter++;
    }
    fclose(fp2);

    printf("\nType something and press enter to overwrite the content:\n");
    fgets(buffer, 10, stdin);

    fp2 = fopen(file, "w");
    fprintf(fp2, "%s", buffer);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit(argv[1]);

    return 0;
}
