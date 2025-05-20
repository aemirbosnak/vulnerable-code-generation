//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to beautify HTML code
void beautifyHTML(char* htmlCode) {
    char* newCode = (char*)malloc(sizeof(char) * (strlen(htmlCode) + 1));
    int i = 0;
    while (htmlCode[i]!= '\0') {
        if (htmlCode[i] == '<' && htmlCode[i+1] == '/') {
            newCode[i] = '<';
            newCode[i+1] = '/';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == '!') {
            newCode[i] = '<';
            newCode[i+1] = '!';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == '[') {
            newCode[i] = '<';
            newCode[i+1] = '[';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == ']') {
            newCode[i] = '<';
            newCode[i+1] = ']';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == 'b') {
            newCode[i] = '<';
            newCode[i+1] = 'b';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == 'i') {
            newCode[i] = '<';
            newCode[i+1] = 'i';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == 'u') {
            newCode[i] = '<';
            newCode[i+1] = 'u';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == 'p') {
            newCode[i] = '<';
            newCode[i+1] = 'p';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == 'br') {
            newCode[i] = '<';
            newCode[i+1] = 'br';
            i += 2;
        }
        else if (htmlCode[i] == '<' && htmlCode[i+1] == 'a') {
            newCode[i] = '<';
            newCode[i+1] = 'a';
            i += 2;
        }
        else {
            newCode[i] = htmlCode[i];
            i++;
        }
    }
    newCode[i] = '\0';
    printf("%s\n", newCode);
    free(newCode);
}

int main() {
    char* htmlCode = "<html><head><title>Title</title></head><body><h1>Heading</h1><p>Paragraph</p></body></html>";
    beautifyHTML(htmlCode);
    return 0;
}