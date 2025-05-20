//FormAI DATASET v1.0 Category: Text processing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000], futuristic_text[1000];
    int i, j, len, pos;

    printf("Enter the text to convert: ");
    gets(text);

    len = strlen(text);
    pos = 0;

    for(i=0; i<len; i++) {
        if(text[i] == ' ') {
            futuristic_text[pos++] = 'S';
            futuristic_text[pos++] = 'P';
            futuristic_text[pos++] = 'A';
            futuristic_text[pos++] = 'C';
            futuristic_text[pos++] = 'E';
        }
        else {
            int random_num = rand() % 10 + 1; // generate random number between 1 and 10

            switch(random_num) {
                case 1:
                    futuristic_text[pos++] = 'Z';
                    futuristic_text[pos++] = 'O';
                    futuristic_text[pos++] = 'O';
                    break;
                case 2:
                    futuristic_text[pos++] = 'N';
                    futuristic_text[pos++] = 'E';
                    futuristic_text[pos++] = 'X';
                    futuristic_text[pos++] = 'U';
                    futuristic_text[pos++] = 'S';
                    break;
                case 3:
                    futuristic_text[pos++] = 'D';
                    futuristic_text[pos++] = 'I';
                    futuristic_text[pos++] = 'G';
                    futuristic_text[pos++] = 'I';
                    break;
                case 4:
                    futuristic_text[pos++] = 'H';
                    futuristic_text[pos++] = 'Y';
                    futuristic_text[pos++] = 'P';
                    futuristic_text[pos++] = 'E';
                    futuristic_text[pos++] = 'R';
                    break;
                case 5:
                    futuristic_text[pos++] = 'A';
                    futuristic_text[pos++] = 'U';
                    futuristic_text[pos++] = 'X';
                    futuristic_text[pos++] = 'I';
                    futuristic_text[pos++] = 'L';
                    break;
                case 6:
                    futuristic_text[pos++] = 'O';
                    futuristic_text[pos++] = 'P';
                    futuristic_text[pos++] = 'T';
                    futuristic_text[pos++] = 'I';
                    futuristic_text[pos++] = 'C';
                    futuristic_text[pos++] = 'S';
                    break;
                case 7:
                    futuristic_text[pos++] = 'Q';
                    futuristic_text[pos++] = 'U';
                    futuristic_text[pos++] = 'A';
                    futuristic_text[pos++] = 'N';
                    futuristic_text[pos++] = 'T';
                    futuristic_text[pos++] = 'U';
                    futuristic_text[pos++] = 'M';
                    break;
                case 8:
                    futuristic_text[pos++] = 'V';
                    futuristic_text[pos++] = 'I';
                    futuristic_text[pos++] = 'R';
                    futuristic_text[pos++] = 'T';
                    futuristic_text[pos++] = 'U';
                    futuristic_text[pos++] = 'A';
                    futuristic_text[pos++] = 'L';
                    break;
                case 9:
                    futuristic_text[pos++] = 'N';
                    futuristic_text[pos++] = 'E';
                    futuristic_text[pos++] = 'O';
                    futuristic_text[pos++] = 'M';
                    futuristic_text[pos++] = 'O';
                    futuristic_text[pos++] = 'R';
                    futuristic_text[pos++] = 'P';
                    break;
                case 10:
                    futuristic_text[pos++] = 'U';
                    futuristic_text[pos++] = 'N';
                    futuristic_text[pos++] = 'I';
                    futuristic_text[pos++] = 'V';
                    futuristic_text[pos++] = 'E';
                    futuristic_text[pos++] = 'R';
                    futuristic_text[pos++] = 'S';
                    futuristic_text[pos++] = 'E';
                    break;
                default:
                    futuristic_text[pos++] = text[i];
            }
        }
    }

    printf("\nFuturistic text: %s", futuristic_text);

    return 0;
}