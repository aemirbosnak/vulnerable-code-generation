//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>

void outputHeader() {
    printf("<!DOCTYPE html>\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("    <title>Welcome to C HTML Beautifier</title>\n");
    printf("</head>\n");
    printf("<body>\n");
}

void outputFooter() {
    printf("</body>\n");
    printf("</html>\n");
}

int main() {
    FILE *inputFile;
    char fileName[50], inputLine[100];
    int indentCount = 0;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    inputFile = fopen(fileName, "r");

    if (!inputFile) {
        printf("Could not open file %s\n", fileName);
        return 1;
    }

    outputHeader();
  
    while (fgets(inputLine, 100, inputFile) != NULL) {
        char currentChar;
        int i;
      
        for (i = 0; i < strlen(inputLine); i++) {
            currentChar = inputLine[i];
            
            switch(currentChar) {
                case '<':
                    printf("%c", currentChar);
                    if (inputLine[i+1] != '/') {
                        indentCount++;
                        printf("\n");
                        for (int j = 0; j < indentCount; j++) {
                            printf("    ");
                        }
                    }
                    break;
                  
                case '>':
                    printf("%c\n", currentChar);
                    if (inputLine[i-1] != '/') {
                        for (int j = 0; j < indentCount; j++) {
                            printf("    ");
                        }
                    }
                    break;
                    
                case '/':
                    if (inputLine[i-1] == '<') {
                        printf("%c", currentChar);
                    } else if (inputLine[i-1] == '-') {
                        printf("%c", currentChar);
                        if (inputLine[i+1] == '-') {
                            printf("\n");
                            for (int j = 0; j < indentCount; j++) {
                                printf("    ");
                            }
                        }
                    }
                    break;
                    
                case '-':
                    if (inputLine[i-1] == '<' && inputLine[i+1] == '-') {
                        printf("%c", currentChar);
                    } else if (inputLine[i-1] == '-' && inputLine[i+1] == '>') {
                        printf("%c\n", currentChar);
                        indentCount--;
                        for (int j = 0; j < indentCount; j++) {
                            printf("    ");
                        }
                    }
                    break;
                  
                default:
                    printf("%c", currentChar);
                    break;
            }
        }
    }
  
    fclose(inputFile);
  
    outputFooter();
  
    return 0;
}