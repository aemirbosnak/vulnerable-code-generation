#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_config(char *filename) {
    char buffer[10];
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Error: Unable to open config file.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
        if (strstr(buffer, "MIGRATE")) {
            // Trigger buffer overflow by calling gets() function
            gets(buffer);
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    read_config(argv[1]);
    printf("Migration complete.\n");
    return 0;
}
