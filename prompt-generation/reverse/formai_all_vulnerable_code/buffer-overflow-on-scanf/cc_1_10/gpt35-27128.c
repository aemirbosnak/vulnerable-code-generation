//FormAI DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *filename) {
    FILE *fp;
    char ch;
    int tab = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF) {
        if(ch == '<') {
            printf("%c", ch);
            ch = fgetc(fp);
            if(ch == '/') {
                printf("\n");
                for(int i = 0; i < tab; i++) {
                    printf("\t");
                }
                printf("%c", ch);
                while(ch != '>') {
                    printf("%c", ch);
                    ch = fgetc(fp);
                }
                printf(">\n");
                tab--;
                for(int i = 0; i < tab; i++) {
                    printf("\t");
                }
            }
            else {
                printf("\n");
                for(int i = 0; i < tab; i++) {
                    printf("\t");
                }
                printf("%c", ch);
                while(ch != '>') {
                    printf("%c", ch);
                    ch = fgetc(fp);
                }
                printf(">");
                tab++;
            }
            printf("\n");
            for(int i = 0; i < tab; i++) {
                printf("\t");
            }
        }
        else {
            printf("%c", ch);
        }
    }
    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter the name of the HTML file: ");
    scanf("%s", filename);
    beautify_html(filename);
    return 0;
}