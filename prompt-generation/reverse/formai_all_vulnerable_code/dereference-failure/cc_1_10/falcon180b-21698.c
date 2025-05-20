//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LEN 4096
#define MAX_TAG_LEN 32

typedef struct {
    char tag[MAX_TAG_LEN];
    char content[MAX_LINE_LEN];
} html_tag;

typedef struct {
    int size;
    html_tag *tags;
} html_doc;

void add_tag(html_doc *doc, char *tag, char *content) {
    if (doc->size >= MAX_LINE_LEN) {
        printf("Error: document too large!\n");
        return;
    }
    strcpy(doc->tags[doc->size].tag, tag);
    strcpy(doc->tags[doc->size].content, content);
    doc->size++;
}

void print_tag(html_tag tag) {
    printf("<%s>%s</%s>\n", tag.tag, tag.content, tag.tag);
}

void print_doc(html_doc doc) {
    int i;
    for (i = 0; i < doc.size; i++) {
        print_tag(doc.tags[i]);
    }
}

int main() {
    char line[MAX_LINE_LEN];
    html_doc doc = {0};
    bool in_tag = false;
    char *tag_content = NULL;
    int tag_content_len = 0;

    printf("Enter HTML code (type 'done' to finish):\n");
    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        if (strcmp(line, "done") == 0) {
            break;
        }
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        if (in_tag) {
            tag_content_len += len;
            tag_content = realloc(tag_content, tag_content_len + 1);
            strcat(tag_content, line);
        } else {
            char *tag = line;
            while (isspace(*tag)) {
                tag++;
            }
            if (*tag == '<') {
                in_tag = true;
                tag++;
                while (*tag!= '>' && *tag!= '\0') {
                    tag++;
                }
                if (*tag == '>') {
                    tag++;
                    add_tag(&doc, tag_content, "");
                } else {
                    printf("Error: unclosed tag!\n");
                }
            } else {
                add_tag(&doc, "p", line);
            }
        }
    }
    print_doc(doc);
    return 0;
}