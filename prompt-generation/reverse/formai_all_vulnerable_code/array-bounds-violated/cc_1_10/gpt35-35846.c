//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int virus_score = 0;

void add_virus(int score) {
    virus_score += score;
}

void check_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return;
    }

    unsigned char buffer[1024];
    while (!feof(file)) {
        fread(buffer, sizeof(unsigned char), 1024, file);
        for (int i = 0; i < 1024 && buffer[i] != 0; i++) {
            if (buffer[i] == 'v' && buffer[i + 1] == 'i' && buffer[i + 2] == 'r' && buffer[i + 3] == 'u' && buffer[i + 4] == 's') {
                add_virus(1);
            }
        }
    }

    fclose(file);
}

void check_directory(char* path) {
    char command[1024];
    sprintf(command, "find %s -type f", path);

    FILE* pipe = popen(command, "r");
    if (!pipe) {
        return;
    }

    char buffer[1024];
    while (!feof(pipe)) {
        fgets(buffer, 1024, pipe);
        buffer[strlen(buffer) - 1] = '\0';
        check_file(buffer);
    }

    pclose(pipe);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    check_directory(argv[1]);

    if (virus_score == 0) {
        printf("Congratulations, no virus detected!\n");
    } else if (virus_score == 1) {
        printf("1 virus detected!\n");
    } else {
        printf("%d viruses detected!\n", virus_score);
    }

    return 0;
}