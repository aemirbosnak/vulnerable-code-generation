//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_HEIGHT 10

int main() {
    char text[MAX_HEIGHT][100] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
    char input_text[100];
    int i, j, k, len, height, width;

    printf("Enter text: ");
    scanf("%[^\n]", input_text);

    len = strlen(input_text);
    width = len / MAX_HEIGHT + 1;

    for (i = 0; i < len; i++) {
        if (input_text[i] == ' ') {
            continue;
        }

        if (i % MAX_HEIGHT == 0) {
            height = 0;
        }

        switch (input_text[i]) {
            case 'A':
                strcpy(text[height], "  AA  ");
                strcat(text[height], " A  A ");
                strcat(text[height], "AAAAA ");
                strcat(text[height], "A  A ");
                strcat(text[height], "A  A ");
                break;
            case 'B':
                strcpy(text[height], "BBBB  ");
                strcat(text[height], "B   B ");
                strcat(text[height], "BBBB  ");
                strcat(text[height], "B   B ");
                strcat(text[height], "BBBB  ");
                break;
            case 'C':
                strcpy(text[height], " CCCC ");
                strcat(text[height], "C     ");
                strcat(text[height], "C     ");
                strcat(text[height], "C     ");
                strcat(text[height], " CCCC ");
                break;
            case 'D':
                strcpy(text[height], "DDDD  ");
                strcat(text[height], "D  DD ");
                strcat(text[height], "D   DD ");
                strcat(text[height], "D  DD ");
                strcat(text[height], "DDDD  ");
                break;
            case 'E':
                strcpy(text[height], "EEEEE ");
                strcat(text[height], "E     ");
                strcat(text[height], "EEE   ");
                strcat(text[height], "E     ");
                strcat(text[height], "EEEEE ");
                break;
            case 'F':
                strcpy(text[height], "FFFFF ");
                strcat(text[height], "F     ");
                strcat(text[height], "FFF   ");
                strcat(text[height], "F     ");
                strcat(text[height], "F     ");
                break;
            case 'G':
                strcpy(text[height], " GGGG ");
                strcat(text[height], "G     ");
                strcat(text[height], "G GGG ");
                strcat(text[height], "G   G ");
                strcat(text[height], " GGGG ");
                break;
            case 'H':
                strcpy(text[height], "H  H  ");
                strcat(text[height], "H  H  ");
                strcat(text[height], "HHHHH ");
                strcat(text[height], "H  H  ");
                strcat(text[height], "H  H  ");
                break;
            case 'I':
                strcpy(text[height], "IIIII ");
                strcat(text[height], "  I   ");
                strcat(text[height], "  I   ");
                strcat(text[height], "  I   ");
                strcat(text[height], "IIIII ");
                break;
            case 'J':
                strcpy(text[height], "JJJJJ ");
                strcat(text[height], "   J  ");
                strcat(text[height], "   J  ");
                strcat(text[height], "J  J ");
                strcat(text[height], " JJ   ");
                break;
            case 'K':
                strcpy(text[height], "K  K  ");
                strcat(text[height], "K K   ");
                strcat(text[height], "KK    ");
                strcat(text[height], "K K   ");
                strcat(text[height], "K  K  ");
                break;
            case 'L':
                strcpy(text[height], "L     ");
                strcat(text[height], "L     ");
                strcat(text[height], "L     ");
                strcat(text[height], "L     ");
                strcat(text[height], "LLLLL ");
                break;
            case 'M':
                strcpy(text[height], "M   M ");
                strcat(text[height], "MM MM ");
                strcat(text[height], "M M M ");
                strcat(text[height], "M   M ");
                strcat(text[height], "M   M ");
                break;
            case 'N':
                strcpy(text[height], "N   N ");
                strcat(text[height], "NN  N ");
                strcat(text[height], "N N N ");
                strcat(text[height], "N  NN ");
                strcat(text[height], "N   N ");
                break;
            case 'O':
                strcpy(text[height], " OOO  ");
                strcat(text[height], "O   O ");
                strcat(text[height], "O   O ");
                strcat(text[height], "O   O ");
                strcat(text[height], " OOO  ");
                break;
            case 'P':
                strcpy(text[height], "PPPP  ");
                strcat(text[height], "P   P ");
                strcat(text[height], "PPPP  ");
                strcat(text[height], "P     ");
                strcat(text[height], "P     ");
                break;
            case 'Q':
                strcpy(text[height], " QQQ  ");
                strcat(text[height], "Q   Q ");
                strcat(text[height], "Q   Q ");
                strcat(text[height], "Q  QQ ");
                strcat(text[height], " QQQ Q");
                break;
            case 'R':
                strcpy(text[height], "RRRR  ");
                strcat(text[height], "R   R ");
                strcat(text[height], "RRRR  ");
                strcat(text[height], "R R   ");
                strcat(text[height], "R  R  ");
                break;
            case 'S':
                strcpy(text[height], " SSSS ");
                strcat(text[height], "S     ");
                strcat(text[height], " SSSS ");
                strcat(text[height], "    S ");
                strcat(text[height], "SSSS  ");
                break;
            case 'T':
                strcpy(text[height], "TTTTT ");
                strcat(text[height], "  T   ");
                strcat(text[height], "  T   ");
                strcat(text[height], "  T   ");
                strcat(text[height], "  T   ");
                break;
            case 'U':
                strcpy(text[height], "U   U ");
                strcat(text[height], "U   U ");
                strcat(text[height], "U   U ");
                strcat(text[height], "U   U ");
                strcat(text[height], " UUU  ");
                break;
            case 'V':
                strcpy(text[height], "V   V ");
                strcat(text[height], "V   V ");
                strcat(text[height], "V   V ");
                strcat(text[height], " V V  ");
                strcat(text[height], "  V   ");
                break;
            case 'W':
                strcpy(text[height], "W   W ");
                strcat(text[height], "W   W ");
                strcat(text[height], "W   W ");
                strcat(text[height], "W W W ");
                strcat(text[height], " W W  ");
                break;
            case 'X':
                strcpy(text[height], "X   X ");
                strcat(text[height], " X X  ");
                strcat(text[height], "  X   ");
                strcat(text[height], " X X  ");
                strcat(text[height], "X   X ");
                break;
            case 'Y':
                strcpy(text[height], "Y   Y ");
                strcat(text[height], " Y Y  ");
                strcat(text[height], "  Y   ");
                strcat(text[height], "  Y   ");
                strcat(text[height], "  Y   ");
                break;
            case 'Z':
                strcpy(text[height], "ZZZZZ ");
                strcat(text[height], "   Z  ");
                strcat(text[height], "  Z   ");
                strcat(text[height], " Z    ");
                strcat(text[height], "ZZZZZ ");
                break;
            default:
                continue;
        }

        height++;
    }

    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 6; k++) {
                if (text[i][2 * j + k] != '\0') {
                    printf("%c", text[i][2 * j + k]);
                } else {
                    printf(" ");
                }
            }
        }

        printf("\n");
    }

    return 0;
}