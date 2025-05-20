//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

/* C Cat Language Translator */
int main() {
    char cat[50],translation[500];
    int i, j;

    printf("Enter a sentence in C Cat Language: \n");
    scanf("%[^\n]s", cat);

    for(i = 0; i < strlen(cat); i++) {
        if(cat[i] == ' ') {
            strcat(translation," ");
            continue;
        }
        else if(cat[i] == 'c' || cat[i] == 'C') {
            strcat(translation,"meow");
        }
        else if(cat[i] == '(') {
            strcat(translation,"purr(");
            continue;
        }
        else if(cat[i] == ')') {
            strcat(translation,")meow");
            continue;
        }
        else if(cat[i] == '{') {
            strcat(translation,"purr{\n");
            j = strlen(translation)-1;
            strcat(translation,"    ");
            while(translation[j] == ' ') {
                strcat(translation,"  ");
                j--;
            }
            continue;
        }
        else if(cat[i] == ';') {
            strcat(translation,"meow;\n");
            j = strlen(translation)-1;
            strcat(translation,"    ");
            while(translation[j] == ' ') {
                strcat(translation,"  ");
                j--;
            }
            continue;
        }
        else if(cat[i] == '}') {
            strcat(translation,"}\nmeow");
            continue;
        }
        else {
            strcat(translation,"meow");
        }
    }
    printf("%s", translation);
    return 0;
}