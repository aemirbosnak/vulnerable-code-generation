//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printCSV(FILE *fp, const char *header, int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (i == 0 && j == 0) {
                fprintf(fp, "%s", header);
            } else if (i == 0) {
                fprintf(fp, "%s,", header);
            } else if (j == 0) {
                fprintf(fp, "%s,", header);
            } else {
                fprintf(fp, "%s,", fgetc(fp));
            }
        }
        fprintf(fp, "\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    char buffer[1024];
    int rowCount = 0;
    int colCount = 0;
    char header[256];

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (buffer[0] == '\n') {
            // Skip empty line
            continue;
        } else if (buffer[0] == '#') {
            // Skip comment line
            continue;
        } else if (buffer[0] == '\0') {
            // Empty line
            break;
        } else {
            // Parse header
            if (rowCount == 0) {
                sscanf(buffer, "%s", header);
                colCount = strlen(header);
                rowCount++;
            } else {
                // Parse data row
                int i;
                for (i = 0; buffer[i]!= ','; i++) {
                    if (buffer[i] == '\n') {
                        break;
                    }
                }
                int j;
                for (j = 0; buffer[i + j]!= '\0'; j++) {
                    if (buffer[i + j] == '\n') {
                        break;
                    }
                }
                int k;
                for (k = 0; buffer[i + j + k]!= '\0'; k++) {
                    if (buffer[i + j + k] == '\n') {
                        break;
                    }
                }
                int m;
                for (m = 0; buffer[i + j + k + m]!= '\0'; m++) {
                    if (buffer[i + j + k + m] == '\n') {
                        break;
                    }
                }
                char *data = malloc((m + 1) * sizeof(char));
                memset(data, 0, (m + 1) * sizeof(char));
                memcpy(data, &buffer[i], j);
                memcpy(data + j, &buffer[i + j], k);
                memcpy(data + j + k, &buffer[i + j + k], m);
                data[m] = '\0';
                printf("%s", data);
            }
        }
    }

    fclose(fp);

    return 0;
}