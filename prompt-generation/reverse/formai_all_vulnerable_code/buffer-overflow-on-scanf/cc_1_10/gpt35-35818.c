//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 50

int main() {
    int i,j=0,flag=0;
    char sentence[1000],word[MAX_WORD_LENGTH+1],filename[50];
    printf("Enter the filename to check: ");
    scanf("%s",filename);

    FILE* fp = fopen(filename,"r");

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while(fgets(sentence,sizeof(sentence),fp)) {
        j++;
        i=0;
        while(sentence[i] != '\0') {
            if(sentence[i] == ' ' || sentence[i] == '\n') {
                word[j] = '\0';
                j=0;
                if(strlen(word) > 0) {
                    for(int x=0;x<strlen(word);x++) {
                        if(!isalpha(word[x])) {
                            flag++;
                            break;
                        }
                    }

                    if(flag == 0) {
                        printf("%s ",word);
                    }
                    else {
                        printf("(%s) ",word);
                        flag=0;
                    }
                }
            }
            else {
                word[j] = sentence[i];
                j++;
            }
            i++;
        }
    }

    fclose(fp);
    return 0;
}