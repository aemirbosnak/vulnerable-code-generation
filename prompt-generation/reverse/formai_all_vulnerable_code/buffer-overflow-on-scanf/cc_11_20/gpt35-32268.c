//FormAI DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dictionary {
    char word[50];
};

int main() {
    int dict_size = 0;
    int i, j, k, l, m;
    char entry[50];
    struct dictionary dict[1000];

    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &dict_size);

    printf("\nEnter %d words in the dictionary: \n", dict_size);
    for(i=0; i<dict_size; i++) {
        scanf("%s", dict[i].word);
    }

    printf("\nEnter the sentence to be spell checked: ");
    getchar(); // to clear the input buffer
    char sentence[200];
    fgets(sentence, 200, stdin);

    char temp[50];
    char output[200] = "";
    char delimiter[2] = " ";
    char *token;

    token = strtok(sentence, delimiter);

    while(token != NULL) {
        strcpy(temp, token);
        int flag = 0;
        for(j=0; j<dict_size; j++) {
            if(strcmp(dict[j].word, temp) == 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            for(k=0; k<strlen(temp); k++) {
                for(l=0; l<dict_size; l++) {
                    for(m=k; m<strlen(temp); m++) {
                        temp[m] = dict[l].word[k];
                        if(strcmp(temp, dict[l].word) == 0) {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 1)
                        break;
                }
                if(flag == 1)
                    break;
            }
            if(flag == 0) {
                char suggestion[50];
                printf("\n%s is not found in the dictionary.\nEnter a suggestion: ", temp);
                scanf("%s", suggestion);

                strcat(output, suggestion);
                strcat(output, " ");
            }
            else {
                strcat(output, temp);
                strcat(output, " ");
            }
        }
        else {
            strcat(output, temp);
            strcat(output, " ");
        }

        token = strtok(NULL, delimiter);
    }

    printf("\nCorrected sentence: \n%s", output);

    return 0;
}