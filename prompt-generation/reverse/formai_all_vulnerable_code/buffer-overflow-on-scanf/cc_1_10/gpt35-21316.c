//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int main() {
    char fileName[100];
    char htmlData[MAX];
    char newHtmlData[MAX];
    FILE *fp;
    int ch, i = 0;

    printf("Enter the input filename: ");
    scanf("%s", fileName);
    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        htmlData[i] = ch;
        i++;
    }
    htmlData[i] = '\0';
    fclose(fp);

    int len = strlen(htmlData);
    int j = 0, k = 0;
    for (i = 0; i < len; i++) {
        if (htmlData[i] == '<') {
            if (htmlData[i + 1] == '/') {
                j--;
            }
            for (int t = 0; t < j; t++) {
                newHtmlData[k] = '\t';
                k++;
            }
            newHtmlData[k] = '<';
            k++;
            j++;
            newHtmlData[k] = '\n';
            k++;
        } else if (htmlData[i] == '>') {
            newHtmlData[k] = '>';
            k++;
            newHtmlData[k] = '\n';
            k++;
        } else {
            newHtmlData[k] = htmlData[i];
            k++;
        }
    }

    fp = fopen("output.html", "w");
    fprintf(fp, "%s", newHtmlData);
    fclose(fp);
    printf("Beautified HTML is saved in 'output.html' file\n");
    return 0;
}