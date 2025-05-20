//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 5000
#define MAX_NAME_LENGTH 50

// Function to read file data from disk
void read_file(char *filename, char *file_data) {
    FILE *fp;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    char c = fgetc(fp);
    while (c != EOF) {
        file_data[count++] = c;
        c = fgetc(fp);
    }
    file_data[count] = '\0';

    fclose(fp);
}

// Function to check for suspicious keywords in file
int search_for_keywords(char *file_data) {
    char keywords[] = "virus|malware|trojan|worm|spyware";
    char *ptr = strstr(file_data, keywords);

    if (ptr != NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char filename[MAX_NAME_LENGTH];
    char file_data[MAX_FILE_SIZE];

    printf("Enter the filename to scan (with extension): ");
    scanf("%s", filename);

    read_file(filename, file_data);

    int suspicious = search_for_keywords(file_data);

    if (suspicious == 1) {
        printf("ALERT! Potential virus or malware detected in file %s\n", filename);
    } else {
        printf("File %s is clean\n", filename);
    }

    return 0;
}