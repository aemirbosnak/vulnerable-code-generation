//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
// "To be or not to be, that is the question"
// A visual representation of Shakespeare's soliloquy as a C data structure

#include <stdio.h>

// Define the main structure of the program
typedef struct {
    char key[10];
    int value;
} node;

// Declare the global variables
node array[10];
int size = 0;

// Add a new node to the array
void add(char key[], int value) {
    node new_node;
    strcpy(new_node.key, key);
    new_node.value = value;
    array[size] = new_node;
    size++;
}

// Retrieve the value corresponding to a key
int get(char key[]) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(array[i].key, key) == 0) {
            return array[i].value;
        }
    }
    return -1;
}

// Remove a node from the array
void remove_node(char key[]) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(array[i].key, key) == 0) {
            int j;
            for (j = i; j < size - 1; j++) {
                array[j] = array[j+1];
            }
            size--;
            return;
        }
    }
}

int main() {

    // Initialize the array with nodes
    add("To", 1);
    add("be", 2);
    add("or", 3);
    add("not", 4);
    add("to", 5);
    add("be", 6);
    add("that", 7);
    add("is", 8);
    add("the", 9);
    add("question", 10);

    // Display the structure of the array
    printf("\n\n\n\n");
    printf("          |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   10  |\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("    key   |  To   |   be  |   or  |  not  |   to  |   be  |  that |   is  |   the |question|\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("  value   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   10  |\n");
    printf("------------------------------------------------------------------------------------------\n");

    // Prompt the user for a key to retrieve
    char search_key[10];
    printf("Enter a key to retrieve: ");
    scanf("%s", search_key);
    int search_value = get(search_key);
    if (search_value != -1) {
        printf("The value corresponding to '%s' is %d\n", search_key, search_value);
    } else {
        printf("'%s' does not exist in the array\n", search_key);
    }

    // Prompt the user for a key to remove
    char remove_key[10];
    printf("Enter a key to remove: ");
    scanf("%s", remove_key);
    remove_node(remove_key);

    // Display the updated structure of the array
    printf("\n\n\n\n");
    printf("          |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("    key   |  To   |   be  |   or  |  not  |   to  |   be  |  that |   is  |   the |\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("  value   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |\n");
    printf("--------------------------------------------------------------------------------\n");

    return 0;
}