//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], code[1000];
    int i, j, len;
    
    printf("Enter a text to convert to Morse code: "); 
    scanf("%[^\n]s", text);
    
    len = strlen(text);

    for (i = 0, j = 0; i < len; i++, j++) {
        switch(text[i]) {
            case 'a':
                strcat(code, ".-");
                break;
            case 'b':
                strcat(code, "-...");
                break;
            case 'c':
                strcat(code, "-.-.");
                break;
            case 'd':
                strcat(code, "-..");
                break;
            case 'e':
                strcat(code, ".");
                break;
            case 'f':
                strcat(code, "..-.");
                break;
            case 'g':
                strcat(code, "--.");
                break;
            case 'h':
                strcat(code, "....");
                break;
            case 'i':
                strcat(code, "..");
                break;
            case 'j':
                strcat(code, ".---");
                break;
            case 'k':
                strcat(code, "-.-");
                break;
            case 'l':
                strcat(code, ".-..");
                break;
            case 'm':
                strcat(code, "--");
                break;
            case 'n':
                strcat(code, "-.");
                break;
            case 'o':
                strcat(code, "---");
                break;
            case 'p':
                strcat(code, ".--.");
                break;
            case 'q':
                strcat(code, "--.-");
                break;
            case 'r':
                strcat(code, ".-.");
                break;
            case 's':
                strcat(code, "...");
                break;
            case 't':
                strcat(code, "-");
                break;
            case 'u':
                strcat(code, "..-");
                break;
            case 'v':
                strcat(code, "...-");
                break;
            case 'w':
                strcat(code, ".--");
                break;
            case 'x':
                strcat(code, "-..-");
                break;
            case 'y':
                strcat(code, "-.--");
                break;
            case 'z':
                strcat(code, "--..");
                break;
            case ' ':
                strcat(code, "/");
                break;
            default:
                j--;
                break;
        }
        if (text[i] != ' ') {
            strcat(code, " ");
        }
    }
    printf("\nYour text in Morse Code: %s\n\n", code);
    return 0;
}