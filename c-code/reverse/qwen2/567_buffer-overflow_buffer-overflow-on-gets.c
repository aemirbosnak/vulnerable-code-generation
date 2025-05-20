#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void parse_c_code(const char *code) {
    const char *keywords[] = {"int", "float", "char", "for", "while", "switch"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    int found_keyword = 0;

    for (int i = 0; i < strlen(code); ++i) {
        if (strncasecmp(&code[i], "int", 3) == 0 ||
            strncasecmp(&code[i], "float", 5) == 0 ||
            strncasecmp(&code[i], "char", 4) == 0 ||
            strncasecmp(&code[i], "for", 3) == 0 ||
            strncasecmp(&code[i], "while", 5) == 0 ||
            strncasecmp(&code[i], "switch", 6) == 0) {
            printf("Found keyword: %.*s\n", 6, &code[i]);
            i += strlen(keywords[strncasecmp(&code[i], "int", 3) == 0 ? 0 :
                             strncasecmp(&code[i], "float", 5) == 0 ? 1 :
                             strncasecmp(&code[i], "char", 4) == 0 ? 2 :
                             strncasecmp(&code[i], "for", 3) == 0 ? 3 :
                             strncasecmp(&code[i], "while", 5) == 0 ? 4 : 5]);
            found_keyword = 1;
        } else if (!isspace(code[i])) {
            printf("Non-keyword character: %c\n", code[i]);
        }
    }

    if (!found_keyword) {
        printf("No keywords found.\n");
    }
}

int main() {
    char code[1000];
    printf("Enter C code: ");
    fgets(code, sizeof(code), stdin);
    parse_c_code(code);
    return 0;
}
