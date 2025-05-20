//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *content;
    int length;
} HtmlSource;

static HtmlSource *
html_read_source(const char *filename)
{
    FILE *fp;
    HtmlSource *source;
    char *buffer;
    int length;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    rewind(fp);
    buffer = malloc(length + 1);
    if (buffer == NULL) {
        fclose(fp);
        return NULL;
    }
    fread(buffer, 1, length, fp);
    fclose(fp);
    buffer[length] = '\0';
    source = malloc(sizeof(HtmlSource));
    if (source == NULL) {
        free(buffer);
        return NULL;
    }
    source->content = buffer;
    source->length = length;
    return source;
}

static void
html_free_source(HtmlSource *source)
{
    if (source == NULL) {
        return;
    }
    free(source->content);
    free(source);
}

static void
html_print_source(const HtmlSource *source)
{
    if (source == NULL) {
        return;
    }
    fwrite(source->content, 1, source->length, stdout);
}

static void
html_beautify_source(HtmlSource *source, int indent)
{
    int i, j, k;
    char *p, *q;
    char *tmp;

    p = source->content;
    while (*p != '\0') {
        if (*p == '<') {
            while (*p != '>' && *p != '\0') {
                p++;
            }
            if (*p == '>') {
                p++;
            }
        } else if (*p == '\n') {
            while (*p == '\n') {
                p++;
            }
        } else {
            q = p + 1;
            while (*q != '\n' && *q != '<' && *q != '\0') {
                q++;
            }
            if (*q == '\n') {
                *q = '\0';
                tmp = malloc(strlen(p) + indent + 1);
                if (tmp == NULL) {
                    return;
                }
                for (i = 0; i < indent; i++) {
                    tmp[i] = ' ';
                }
                strcpy(tmp + indent, p);
                *q = '\n';
                strcpy(p, tmp);
                p += strlen(tmp);
                free(tmp);
            } else if (*q == '<') {
                *q = '\0';
                tmp = malloc(strlen(p) + 1);
                if (tmp == NULL) {
                    return;
                }
                strcpy(tmp, p);
                *q = '<';
                p += strlen(tmp);
                for (i = 0; i < indent; i++) {
                    p[i] = ' ';
                }
                strcpy(p + indent, tmp);
                free(tmp);
            } else {
                p = q;
            }
        }
    }

    /* compress multiple spaces */
    p = source->content;
    while (*p != '\0') {
        if (*p == ' ') {
            while (*p == ' ') {
                p++;
            }
        } else {
            p++;
        }
    }

    /* compress multiple newlines */
    p = source->content;
    while (*p != '\0') {
        if (*p == '\n') {
            while (*p == '\n') {
                p++;
            }
        } else {
            p++;
        }
    }

    /* remove trailing spaces */
    p = source->content + source->length - 1;
    while (*p == ' ') {
        p--;
    }
    *p = '\0';

    /* remove leading spaces */
    p = source->content;
    while (*p == ' ') {
        p++;
    }
    source->content = p;
    source->length = strlen(source->content);
}

int
main(int argc, char **argv)
{
    HtmlSource *source;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }
    source = html_read_source(argv[1]);
    if (source == NULL) {
        fprintf(stderr, "Failed to read HTML file: %s\n", argv[1]);
        return 1;
    }
    html_beautify_source(source, 4);
    html_print_source(source);
    html_free_source(source);
    return 0;
}