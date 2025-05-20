//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_SIZE 20
#define MAX_ATTR_SIZE 20

typedef struct {
    char tag[MAX_TAG_SIZE];
    char attr_name[MAX_ATTR_SIZE];
    char attr_value[MAX_ATTR_SIZE];
} element;

int main() {
    char xml_str[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><bookstore><book category=\"children\"><title>The Cat in the Hat</title><author>Dr. Seuss</author><year>1957</year><price>6.99</price></book><book category=\"web\"><title>Learning XML</title><author>Erik T. Ray</author><year>2003</year><price>39.95</price></book></bookstore>";
    char* p = xml_str;
    element e;
    int len;
    char c;

    while (*p) {
        if (*p == '<') {
            p++;
            len = 0;

            while (*p != '>') {
                e.tag[len++] = *p++;
            }

            e.tag[len] = '\0';

            if (strcmp(e.tag, "book") == 0) {
                printf("<%s ", e.tag);

                while (*p != '>') {
                    if (*p == ' ') {
                        p++;
                        len = 0;

                        while (*p != '=') {
                            e.attr_name[len++] = *p++;
                        }

                        e.attr_name[len] = '\0';
                        printf("%s=", e.attr_name);

                        p++;
                        c = *p++;
                        len = 0;

                        while (*p != c) {
                            e.attr_value[len++] = *p++;
                        }

                        e.attr_value[len] = '\0';
                        printf("\"%s\" ", e.attr_value);
                    }
                    else {
                        p++;
                    }
                }

                printf(">\n");
            }
            else if (strcmp(e.tag, "/book") == 0) {
                printf("</%s>\n", e.tag);
            }
            else {
                printf("<%s>\n", e.tag);
            }
        }
        else {
            p++;
        }
    }

    return 0;
}