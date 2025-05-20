//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME_SIZE 100
#define MAX_FILE_SIZE 1000000

// Function to convert string to lower case
void toLowerCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to check if the file contains virus signature
int virusCheck(char *fileName, char *virusSignature) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    int bytesRead;

    fp = fopen(fileName, "rb");
    if (!fp) {
        printf("Error: Cannot open file \"%s\".\n", fileName);
        return 0;
    }

    bytesRead = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    if (bytesRead < strlen(virusSignature)) {
        return 0;
    }

    toLowerCase(buffer);
    toLowerCase(virusSignature);

    if (strstr(buffer, virusSignature) != NULL) {
        return 1;
    }

    return 0;
}

int main() {
    char fileName[FILE_NAME_SIZE];
    char virusSignature[] = "myvirus";
    int result = 0;

    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    result = virusCheck(fileName, virusSignature);

    if (result == 1) {
        printf("Virus found in file \"%s\".\n", fileName);
    } else {
        printf("No virus found in file \"%s\".\n", fileName);
    }

    return 0;
}