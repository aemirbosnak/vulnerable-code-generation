//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
/* Welcome to the C Antivirus Scanner program! */
#include <stdio.h>
#include <string.h>

int main() {

    char fileName[25], extension[5], deleteFile[3], virus[12];
    int fileSize, n = 0, i, suspicious = 0;

    printf("\nWelcome to the C Antivirus Scanner program!\n");
    printf("\nEnter the file name (without extension): ");
    scanf("%s", fileName);

    printf("\nEnter the file extension (e.g. txt, doc, pdf): ");
    scanf("%s", extension);

    strcat(fileName, ".");
    strcat(fileName, extension);

    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("\nError: Unable to open file!\n");
        return 0;
    }

    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);

    if (fileSize > 1024) {
        printf("\nFile size too big to scan! \n");
    } else {

        char fileData[fileSize];
        char virusList[12][10] = {"trojan", "adware", "worms", "spyware", "ransomware", "keylogger", "malware", "virus", "rootkit", "phishing", "botnets", "backdoor"};

        printf("\nFile name: %s\n", fileName);
        printf("File size: %d bytes\n", fileSize);

        rewind(fp);
        fread(fileData, sizeof(char), fileSize, fp);

        for (i = 0; i < 12; i++) {
            if (strstr(fileData, virusList[i]) != NULL) {
                strcpy(virus, virusList[i]);
                suspicious = 1;
                break;
            }
        }

        if (suspicious == 1) {
            printf("\nFile is infected with %s! \n", virus);
            printf("\nDo you want to delete the file (Y/N)? ");
            scanf("%s", deleteFile);

            if (strcmp(deleteFile, "Y") == 0 || strcmp(deleteFile, "y") == 0) {
                remove(fileName);
                printf("\nFile has been deleted! \n");
            } else {
                printf("\nFile has NOT been deleted! \n");
            }

        } else {
            printf("\nFile is NOT infected! \n");
        }

    }

    fclose(fp);
    printf("\nThank you for using the C Antivirus Scanner! \n");
    return 0;

}