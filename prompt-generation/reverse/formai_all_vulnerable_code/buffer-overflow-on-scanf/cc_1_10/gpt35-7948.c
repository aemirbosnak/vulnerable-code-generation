//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_NUM_FILES 50
#define MAX_NUM_VIRUSES 3

char VIRUS_LIST[MAX_NUM_VIRUSES][20] = {"Trojan", "Worm", "Malware"};
int virusCount[MAX_NUM_VIRUSES];

void scanFile(char* fileName);
void printResults();

void main()
{
    printf("Welcome to the C Antivirus Scanner!\n");
    printf("Please enter the file paths separated by a space:\n");

    char fileNames[MAX_NUM_FILES][MAX_FILE_NAME_LEN];
    int numFiles = 0;

    while(numFiles < MAX_NUM_FILES) {
        scanf("%s", fileNames[numFiles]);
        if(strcmp(fileNames[numFiles], "-1") == 0) {
            break;
        } else {
            numFiles++;
        }
    }

    for(int i=0; i<numFiles; i++) {
        scanFile(fileNames[i]);
    }

    printResults();
}

void scanFile(char* fileName) 
{
    printf("Scanning file: %s\n", fileName);
    FILE *filePtr = fopen(fileName, "r");
    char line[MAX_LINE_LEN];

    while(fgets(line, MAX_LINE_LEN, filePtr) != NULL) {
        for(int i=0; i<MAX_NUM_VIRUSES; i++) {
            char *virusName = VIRUS_LIST[i];
            if(strstr(line, virusName) != NULL) {
                virusCount[i]++;
                printf("%s found in file %s\n", virusName, fileName);
                break;
            }
        }
    }

    fclose(filePtr);
}

void printResults()
{
    printf("\n\n---------- SCAN RESULTS ----------\n");
    int totalViruses = 0;

    for(int i=0; i<MAX_NUM_VIRUSES; i++) {
        printf("%s count: %d\n", VIRUS_LIST[i], virusCount[i]);
        totalViruses += virusCount[i];
    }

    if(totalViruses == 0) {
        printf("No viruses found!\n");
    } else {
        printf("Total Viruses Found: %d\n", totalViruses);
    }
}