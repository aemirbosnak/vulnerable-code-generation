//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_HTML_TAGS 20

typedef struct {
    char *tag;
    int length;
} HTMLTag;

HTMLTag htmlTags[MAX_HTML_TAGS] = {
    {"<html>", 6},
    {"</html>", 7},
    {"<head>", 6},
    {"</head>", 7},
    {"<title>", 7},
    {"</title>", 8},
    {"<body>", 6},
    {"</body>", 7},
    {"<h1>", 4},
    {"</h1>", 5},
    {"<h2>", 4},
    {"</h2>", 5},
    {"<h3>", 4},
    {"</h3>", 5},
    {"<p>", 3},
    {"</p>", 4},
    {"<br>", 4},
    {"<ul>", 4},
    {"</ul>", 5},
    {"<li>", 3},
    {"</li>", 4}
};

void beautifyHTML(char *html) {
    int i, j, k, tagIndex;
    char *currentTag;
    char *formattedHTML = malloc(strlen(html) + 1);

    strcpy(formattedHTML, html);

    for (i = 0; i < strlen(formattedHTML); i++) {
        if (formattedHTML[i] == '<') {
            currentTag = &formattedHTML[i];
            while (currentTag[0]!= '>' && currentTag - formattedHTML < strlen(formattedHTML)) {
                currentTag++;
            }

            tagIndex = -1;
            for (j = 0; j < MAX_HTML_TAGS; j++) {
                if (strncmp(currentTag, htmlTags[j].tag, htmlTags[j].length) == 0) {
                    tagIndex = j;
                    break;
                }
            }

            if (tagIndex!= -1) {
                formattedHTML[i + htmlTags[tagIndex].length - 1] = '\0';
                strcat(formattedHTML, "\n");
                strcat(formattedHTML, &currentTag[1]);
                strcat(formattedHTML, "\n");
                i += htmlTags[tagIndex].length - 1;
            }
        }
    }

    printf("%s", formattedHTML);
    free(formattedHTML);
}

int main() {
    char html[MAX_LINE_LENGTH];

    printf("Enter HTML code:\n");
    fgets(html, MAX_LINE_LENGTH, stdin);

    beautifyHTML(html);

    return 0;
}