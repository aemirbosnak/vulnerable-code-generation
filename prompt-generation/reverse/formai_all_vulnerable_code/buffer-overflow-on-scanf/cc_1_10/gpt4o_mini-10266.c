//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODES 100
#define MAX_LEN 100

typedef struct {
    char code[MAX_LEN];
    int line_number;
} CodeSnippet;

void addSnippet(CodeSnippet snippets[], int *count, const char *code) {
    if (*count >= MAX_CODES) {
        printf("😕 Oops! Can't add more snippets, maximum reached.\n");
        return;
    }
    snprintf(snippets[*count].code, MAX_LEN, "%s", code);
    snippets[*count].line_number = *count + 1; // Line number starts from 1
    (*count)++;
    printf("🎉 Snippet added! Line number: %d\n", snippets[*count - 1].line_number);
}

void listSnippets(CodeSnippet snippets[], int count) {
    printf("📝 List of snippets:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", snippets[i].line_number, snippets[i].code);
    }
}

void parseCode(const CodeSnippet *snippet) {
    printf("🚀 Parsing code on line %d:\n", snippet->line_number);
    // Simple parsing example just counting the opening and closing braces
    int openBraces = 0, closeBraces = 0;

    for (int i = 0; i < strlen(snippet->code); i++) {
        if (snippet->code[i] == '{') {
            openBraces++;
        } else if (snippet->code[i] == '}') {
            closeBraces++;
        }
    }

    if (openBraces == closeBraces) {
        printf("💡 All braces are matching! (Opened: %d, Closed: %d)\n", openBraces, closeBraces);
    } else {
        printf("⚠️ Mismatched braces! (Opened: %d, Closed: %d)\n", openBraces, closeBraces);
    }
}

int main() {
    CodeSnippet snippets[MAX_CODES];
    int snippetCount = 0;

    char choice;
    char code[MAX_LEN];

    printf("🌟 Welcome to the C Syntax Parser! 🌟\n");

    while (1) {
        printf("Choose an action:\n");
        printf("1. Add a code snippet\n");
        printf("2. List all snippets\n");
        printf("3. Parse a specific snippet\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter your C code snippet (end with a single line of 'END'):\n");
                snprintf(code, sizeof(code), "");
                while (1) {
                    char line[MAX_LEN];
                    fgets(line, sizeof(line), stdin);
                    if (strcmp(line, "END\n") == 0) {
                        break;
                    }
                    strcat(code, line);
                }
                addSnippet(snippets, &snippetCount, code);
                break;

            case '2':
                listSnippets(snippets, snippetCount);
                break;

            case '3':
                if (snippetCount == 0) {
                    printf("😞 No snippets available to parse! Add some first!\n");
                    break;
                }
                printf("Enter the line number of the snippet to parse (1-%d): ", snippetCount);
                int lineNumber;
                scanf("%d", &lineNumber);
                if (lineNumber < 1 || lineNumber > snippetCount) {
                    printf("🤔 Invalid line number!\n");
                } else {
                    parseCode(&snippets[lineNumber - 1]);
                }
                break;

            case '4':
                printf("👋 Thank you for using the C Syntax Parser! Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid option! Please select again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}