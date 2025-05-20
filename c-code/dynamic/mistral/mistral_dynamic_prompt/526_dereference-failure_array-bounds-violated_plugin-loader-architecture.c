#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[20];
    void (*func)();
    struct Plugin *next;
} Plugin;

Plugin *head = NULL;

void load_plugin(Plugin *new) {
    new->next = head;
    head = new;
}

void execute_plugins() {
    Plugin *current = head;
    while (current != NULL) {
        current->func();
        current = current->next;
    }
}

void plugin_func_example_1() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Array length: %ld\n", sizeof(arr) / sizeof(arr[0])); // Incorrect calculation of array length
    printf("First element: %d\n", arr[-1]); // Accessing array out of bounds
}

void plugin_func_example_2() {
    char str[] = "This is a sample string";
    printf("%c\n", str[strlen(str)]); // Accessing string out of bounds by getting string length and indexing one more than the actual length
}

int main() {
    Plugin p1 = {.name = "Example Plugin 1", .func = plugin_func_example_1};
    Plugin p2 = {.name = "Example Plugin 2", .func = plugin_func_example_2};

    load_plugin(&p1);
    load_plugin(&p2);
    execute_plugins();

    return 0;
}
