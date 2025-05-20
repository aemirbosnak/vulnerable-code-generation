//FormAI DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576 // 1 MB

int main() {
    char filename[30], data[MAX_FILE_SIZE];
    int i, j, len;

    printf("My love, please tell me the name of the file you want to recover: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Oops! It seems like the file does not exist...\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    rewind(fp);

    if (len > MAX_FILE_SIZE) {
        printf("Sorry my love, but the file is too big for me to recover...\n");
        return 0;
    }

    // Reading file contents
    fread(data, sizeof(char), len, fp);

    // Modifying the data in a romantic way
    for (i = 0; i < len; i++) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            for (j = i+1; j < len; j++) {
                if (data[j] >= 'A' && data[j] <= 'Z') {
                    char temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                    break;
                }
            }
        } else if (data[i] >= 'A' && data[i] <= 'Z') {
            for (j = i+1; j < len; j++) {
                if (data[j] >= 'a' && data[j] <= 'z') {
                    char temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                    break;
                }
            }
        }
    }

    // Writing the modified data to a new file
    char new_filename[30] = "love_";
    strcat(new_filename, filename);
    FILE *new_fp = fopen(new_filename, "w");
    fwrite(data, sizeof(char), len, new_fp);
    fclose(new_fp);

    printf("My love, I have recovered the file with a romantic twist! Please check 'love_%s' file.\n", filename);
    fclose(fp);
    return 0;
}