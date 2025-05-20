//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: immersive
#include <stdio.h>
#include <string.h>

// translate function to convert C Cat Language to English
void translate(char c_cat[]) {
    char english[300] = "";
    char word[50] = ""; // buffer to hold current word being translated
    int i = 0, j = 0;

    while (c_cat[i] != '\0') {
        if (c_cat[i] == 'm') { // "meow" indicates a variable
            strcat(english, "int ");
            i += 4; // skip past "meow"
            while (c_cat[i] != ' ') { // get variable name
                strncat(word, &c_cat[i], 1);
                i++;
            }
            strcat(english, word); // add variable name to translation
            strcat(english, ";\n");
            memset(word, 0, sizeof(word)); // clear buffer
        }
        else if (c_cat[i] == 'p') { // "purr" indicates a printf statement
            strcat(english, "printf(");
            i += 4; // skip past "purr"
            while (c_cat[i] != ')') { // get string within parentheses
                strncat(word, &c_cat[i], 1);
                i++;
            }
            strcat(english, "\""); // add quotes around string for printf
            strcat(english, word);
            strcat(english, "\"");
            strcat(english, ");\n");
            memset(word, 0, sizeof(word)); // clear buffer
        }
        else if (c_cat[i] == 'h') { // "hiss" indicates an if statement
            strcat(english, "if (");
            i += 4; // skip past "hiss"
            while (c_cat[i] != '{') { // get condition within parentheses
                strncat(word, &c_cat[i], 1);
                i++;
            }
            strcat(english, word);
            strcat(english, ") {\n");
            memset(word, 0, sizeof(word)); // clear buffer

            // get code within curly braces
            i++; // skip past opening curly brace
            while (c_cat[i] != '}') {
                if (c_cat[i] == 'm') { // "meow" within if statement is a variable
                    strcat(english, "int ");
                    i += 4; // skip past "meow"
                    while (c_cat[i] != ' ') { // get variable name
                        strncat(word, &c_cat[i], 1);
                        i++;
                    }
                    strcat(english, word); // add variable name to translation
                    strcat(english, ";\n");
                    memset(word, 0, sizeof(word)); // clear buffer
                }
                else if (c_cat[i] == 'p') { // "purr" within if statement is a printf
                    strcat(english, "printf(");
                    i += 4; // skip past "purr"
                    while (c_cat[i] != ')') { // get string within parentheses
                        strncat(word, &c_cat[i], 1);
                        i++;
                    }
                    strcat(english, "\""); // add quotes around string for printf
                    strcat(english, word);
                    strcat(english, "\"");
                    strcat(english, ");\n");
                    memset(word, 0, sizeof(word)); // clear buffer
                }
                else if (c_cat[i] == 'h') { // nested "hiss" within if statement
                    strcat(english, "if (");
                    i += 4; // skip past "hiss"
                    while (c_cat[i] != '{') { // get condition within parentheses
                        strncat(word, &c_cat[i], 1);
                        i++;
                    }
                    strcat(english, word);
                    strcat(english, ") {\n");
                    memset(word, 0, sizeof(word)); // clear buffer
                }
                else if (c_cat[i] == '}') { // closing curly brace of nested if statement
                    strcat(english, "}\n");
                }

                i++;
            }

            strcat(english, "}\n"); // closing curly brace of if statement
        }

        i++;
    }

    printf("%s", english);
}

int main() {
    char input[300];
    printf("Enter C Cat Language code:\n");
    gets(input);

    translate(input);

    return 0;
}