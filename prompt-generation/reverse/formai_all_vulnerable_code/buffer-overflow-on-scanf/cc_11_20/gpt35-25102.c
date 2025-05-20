//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>

int main() {

    char word[20];
    int count, i, j, k;
    int letters[20] = {0};

    printf("Enter a word: ");
    scanf("%s", word);

    for(i = 0; word[i] != '\0'; i++) {
        count = 1;
        for(j = i + 1; word[j] != '\0'; j++) {
            if(word[i] == word[j]) {
                count++;
                letters[j] = 1;
            }
        }
        if(letters[i] != 1) {
            letters[i] = count;
        }
    }

    printf("\n\nThe ASCII art for \'%s\' is:\n\n", word);

    for(i = 0; word[i] != '\0'; i++) {
        printf("   ");
        for(j = 1; j <= letters[i]; j++) {
            for(k = 1; k <= 4; k++) {
                if(j == letters[i] && k == 3) {
                    printf("%c", word[i]);
                } else {
                    if(k == 3) {
                        printf("|");
                    } else if(j == 1) {
                        printf("\\");
                    } else if(j == letters[i]) {
                        printf("/");
                    } else {
                        printf(" ");
                    }
                }
            }
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}