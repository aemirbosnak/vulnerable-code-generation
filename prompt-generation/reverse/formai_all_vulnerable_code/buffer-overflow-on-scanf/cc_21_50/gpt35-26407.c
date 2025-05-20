//FormAI DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char word[100], dictionary[50][100];
    int i, j, n, k, isCorrect;

    printf("\n\t\t-----------------------------------\n");
    printf("\t\t|   Surprise Spell Checker Code!  |\n");
    printf("\t\t-----------------------------------\n");

    printf("\nEnter the number of words in the dictionary : ");
    scanf("%d", &n);

    printf("\nEnter %d words in the dictionary\n", n);
    for(i = 0; i < n; i++){
        scanf("%s", dictionary[i]);
        for(j = 0; j < strlen(dictionary[i]); j++){
            dictionary[i][j] = tolower(dictionary[i][j]);
        }
    }

    printf("\nEnter a word for spell check: ");
    scanf("%s", word);

    for(i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }

    for(i = 0; i < n; i++){
        if(strcmp(word,dictionary[i]) == 0){
            printf("\n%s is spelled correctly!\n", word);
            isCorrect = 1;
            break;
        }
    }

    if(!isCorrect){
        printf("\nThe spelling of %s is incorrect. Similar words from the dictionary are: \n", word);
        for(i = 0; i < n; i++){
            isCorrect = 1;
            if(strlen(word) == strlen(dictionary[i])){
                for(j = 0; j < strlen(dictionary[i]); j++){
                    if(word[j] != dictionary[i][j]){
                        isCorrect = 0;
                        break;
                    }
                }
                if(!isCorrect){
                    printf("%s\n", dictionary[i]);
                }
            }else if(strlen(word) == strlen(dictionary[i]) + 1){
                k = 0;
                for(j = 0; j < strlen(word); j++){
                    if(word[j] != dictionary[i][k]){
                        k++;
                        if(word[j] != dictionary[i][k]){
                            isCorrect = 0;
                            break;
                        }
                    }
                    k++;
                }
                if(!isCorrect){
                    printf("%s\n", dictionary[i]);
                }
            }else if(strlen(word) + 1 == strlen(dictionary[i])){
                k = 0;
                for(j = 0; j < strlen(dictionary[i]); j++){
                    if(dictionary[i][j] != word[k]){
                        k++;
                        if(dictionary[i][j] != word[k]){
                            isCorrect = 0;
                            break;
                        }
                    }
                    k++;
                }
                if(!isCorrect){
                    printf("%s\n", dictionary[i]);
                }
            }
        }
    }

    printf("\n\n\t\t--------------------------\n");
    printf("\t\t|   End of Spell Checker  |\n");
    printf("\t\t--------------------------\n");

    return 0;
}