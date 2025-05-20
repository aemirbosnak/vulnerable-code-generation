//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 100
#define MAX_ATTR_NUM 10
#define MAX_ATTR_NAME_LEN 50
#define MAX_ATTR_VALUE_LEN 50

struct attribute {
    char name[MAX_ATTR_NAME_LEN];
    char value[MAX_ATTR_VALUE_LEN];
};

struct element {
    char tag[MAX_TAG_LEN];
    struct attribute attrs[MAX_ATTR_NUM];
    int attr_count;
    char content[MAX_TAG_LEN];
    struct element *subelements[MAX_TAG_LEN];
    int subelem_count;
};

void parse_xml(char *filename, struct element *root) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_TAG_LEN];
    struct element *stack[MAX_TAG_LEN];
    int stack_size = 0;

    while (fgets(line, MAX_TAG_LEN, file) != NULL) {
        if (stack_size == 0) {
            root->attr_count = 0;
            root->subelem_count = 0;
        }

        if (line[0] == '<' && line[1] == '/') { // closing tag
            stack_size--;
            if (stack_size < 0) {
                printf("Error: unexpected closing tag\n");
                exit(1);
            }

            struct element *parent = stack[stack_size];
            if (strcmp(line + 2, parent->tag) != 0) {
                printf("Error: closing tag doesn't match opening tag\n");
                exit(1);
            }

            if (parent->subelem_count > 0) {
                struct element **last_subelem = &parent->subelements[parent->subelem_count - 1];
                if (*last_subelem != NULL && strlen((*last_subelem)->content) == 0) {
                    (*last_subelem)->subelements[0] = NULL;
                    (*last_subelem)->subelem_count = 0;
                }
            }
        }
        else if (line[0] == '<') { // opening tag
            int is_closing_tag = (line[strlen(line) - 2] == '/');
            if (is_closing_tag) {
                line[strlen(line) - 2] = '\0';
            }

            struct element *elem = malloc(sizeof(struct element));
            if (elem == NULL) {
                printf("Error: out of memory\n");
                exit(1);
            }

            char *space_pos = strchr(line, ' ');
            if (space_pos == NULL || space_pos > strchr(line, '>')) {
                printf("Error: invalid tag\n");
                exit(1);
            }

            memcpy(elem->tag, line + 1, space_pos - line - 1);
            elem->tag[space_pos - line - 1] = '\0';

            if (!is_closing_tag) {
                stack[stack_size] = elem;
                stack_size++;

                elem->attr_count = 0;
                elem->subelem_count = 0;

                int pos = 0;
                while (1) {
                    char *equals_pos = strchr(space_pos + 1, '=');
                    if (equals_pos == NULL || equals_pos > strchr(line, '>')) {
                        break;
                    }

                    int name_len = equals_pos - space_pos - 1;
                    int value_len = strchr(equals_pos + 1, '\"') - equals_pos - 1;
                    if (name_len >= MAX_ATTR_NAME_LEN || value_len >= MAX_ATTR_VALUE_LEN) {
                        printf("Error: attribute name or value is too long\n");
                        exit(1);
                    }

                    memcpy(elem->attrs[elem->attr_count].name, space_pos + 1, name_len);
                    elem->attrs[elem->attr_count].name[name_len] = '\0';

                    memcpy(elem->attrs[elem->attr_count].value, equals_pos + 2, value_len);
                    elem->attrs[elem->attr_count].value[value_len] = '\0';

                    elem->attr_count++;
                    pos = strchr(line, '>') - line;
                }

                if (line[pos - 1] != '/') {
                    if (stack_size == 1) {
                        strcpy(root->content, line + pos + 1);
                    }
                    else {
                        struct element *parent = stack[stack_size - 2];
                        parent->subelements[parent->subelem_count] = elem;
                        parent->subelem_count++;
                    }
                }
            }
        }
        else { // text node
            if (stack_size == 0) {
                printf("Error: text node at root level\n");
                exit(1);
            }
            struct element *parent = stack[stack_size - 1];
            if (parent->subelem_count == 0) {
                strcpy(parent->content, line);
            }
            else {
                struct element *last_subelem = parent->subelements[parent->subelem_count - 1];
                if (last_subelem != NULL) {
                    strcat(last_subelem->content, line);
                }
            }
        }
    }

    fclose(file);
}

void print_element(struct element *elem, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("<%s", elem->tag);
    for (int i = 0; i < elem->attr_count; i++) {
        printf(" %s=\"%s\"", elem->attrs[i].name, elem->attrs[i].value);
    }
    printf(">");

    if (strlen(elem->content) > 0) {
        printf("%s", elem->content);
    }

    if (elem->subelem_count > 0) {
        printf("\n");
        for (int i = 0; i < elem->subelem_count; i++) {
            print_element(elem->subelements[i], depth + 1);
        }
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
    }

    printf("</%s>\n", elem->tag);
}

int main() {
    struct element root;
    parse_xml("example.xml", &root);
    print_element(&root, 0);
    return 0;
}