//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Determine if a file is infected
int is_infected(char *filename) {
    FILE *fp;
    char ch;
    int i = 0;

    fp = fopen(filename, "r");
    while((ch = fgetc(fp)) != EOF) {
        if(ch == 'v' && i == 0) {
            i++;
        } else if(ch == 'i' && i == 1) {
            i++;
        } else if(ch == 'r' && i == 2) {
            i++;
        } else if(ch == 'u' && i == 3) {
            i++;
        } else if(ch == 's' && i == 4) {
            i++;
        } else if(ch == ' ' && i == 5) {
            i++;
        } else if(ch == 'c' && i == 6) {
            i++;
        } else if(ch == 'a' && i == 7) {
            i++;
        } else if(ch == 'n' && i == 8) {
            fclose(fp);
            return 1;
        } else {
            i = 0;
        }
    }

    fclose(fp);
    return 0;
}

// Scan all files in a directory
void scan_directory(char *directory, char *virus_signature) {
    char *command;
    char *filename;
    int filename_length;
    char *dot_position;
    char *file_extension;
    char *infected_message = "File '%s' is infected with '%s'\n";
    int is_infected_flag = 0;

    command = malloc(strlen(directory) + 7);
    sprintf(command, "ls %s", directory);

    FILE *fp = popen(command, "r");

    while(fscanf(fp, "%ms", &filename) != EOF) {
        dot_position = strrchr(filename, '.');
        if(dot_position == NULL) {
            continue;
        }

        file_extension = dot_position + 1;
        filename_length = strlen(filename);

        if(
            strcmp(file_extension, "c") == 0 &&
            filename_length >= strlen(virus_signature)
        ) {
            is_infected_flag = is_infected(filename);
            if(is_infected_flag) {
                printf(infected_message, filename, virus_signature);
            }
        }

        free(filename);
    }

    pclose(fp);
}

int main(int argc, char **argv) {
    char *virus_signature = "virus can";
    char *directory;
    int i;

    if(argc < 2) {
        printf("Please specify directory to scan. Usage: %s directory1 directory2 ...\n", argv[0]);
        return 1;
    }

    for(i = 1; i < argc; i++) {
        directory = argv[i];
        scan_directory(directory, virus_signature);
    }

    return 0;
}