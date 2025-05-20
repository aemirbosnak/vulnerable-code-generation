//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include<stdio.h>
#include<string.h>

// Function to translate C Cat Language to English
void c_cat_translator(char input[]) {
    char output[1000] = "";
    char temp[100] = "";
    int index = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'm') {
            strcat(temp, "eow");
            strcat(output, temp);
            index += 3;
            memset(temp,0,sizeof(temp));
        }
        else if (input[i] == 'r') {
            strcat(temp, "meow");
            strcat(output, temp);
            index += 4;
            memset(temp,0,sizeof(temp));
        }
        else if (input[i] == 'c') {
            strcat(temp, "purr");
            strcat(output, temp);
            index += 4;
            memset(temp,0,sizeof(temp));
        }
        else if (input[i] == 'o') {
            strcat(temp, "hiss");
            strcat(output, temp);
            index += 4;
            memset(temp,0,sizeof(temp));
        }
        else if (input[i] == 'w') {
            strcat(temp, "paw");
            strcat(output, temp);
            index += 3;
            memset(temp,0,sizeof(temp));
        }
        else if (input[i] == 'h') {
            strcat(temp, "scratch");
            strcat(output, temp);
            index += 7;
            memset(temp,0,sizeof(temp));
        }
        else {
            temp[0] = input[i];
            strcat(output, temp);
            index += 1;
            memset(temp,0,sizeof(temp));
        }
    }
    printf("%s", output);
}

int main() 
{
    char input[1000];
    printf("Enter C Cat Language to translate: ");
    scanf("%[^\n]", input);
    c_cat_translator(input);
    return 0;
}