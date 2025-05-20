//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_KNIGHTS 100
#define MAX_NAME_LENGTH 50

// A chivalrous knight structure to store the name and valor
typedef struct {
    char name[MAX_NAME_LENGTH];
    int valor;
} Knight;

// A wise function to perform a linear search among the noble knights
int search_knight(Knight knights[], int count, const char* knight_name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(knights[i].name, knight_name) == 0) {
            return i; // Found the knight, return the index
        }
    }
    return -1; // Knight not found in the realm
}

// A grand function to display all the gallant knights
void display_knights(Knight knights[], int count) {
    printf("The Noble Knights of the Realm:\n");
    for (int i = 0; i < count; i++) {
        printf("Knight: %s, Valor: %d\n", knights[i].name, knights[i].valor);
    }
}

// The assembly of knights in the great hall
void assemble_knights(Knight knights[], int* count) {
    printf("Enter the number of knights gathered (max %d): ", MAX_KNIGHTS);
    scanf("%d", count);

    if (*count > MAX_KNIGHTS) {
        printf("Alas! The number of knights exceeds the limit.\n");
        *count = MAX_KNIGHTS;
    }

    for (int i = 0; i < *count; i++) {
        printf("Name of Knight %d: ", i + 1);
        scanf("%s", knights[i].name);
        printf("Valor of Knight %s: ", knights[i].name);
        scanf("%d", &knights[i].valor);
    }
}

int main() {
    Knight noble_knights[MAX_KNIGHTS];
    int knight_count = 0;
    char search_name[MAX_NAME_LENGTH];
    
    // Assemble the noble knights
    assemble_knights(noble_knights, &knight_count);
    
    // Display the assembled knights
    display_knights(noble_knights, knight_count);
    
    // Quest to find a particular knight
    printf("Enter the name of the knight you seek: ");
    scanf("%s", search_name);
    
    // Invoke the search function
    int index = search_knight(noble_knights, knight_count, search_name);
    
    if (index != -1) {
        printf("Huzzah! Knight %s found with valor of %d!\n", noble_knights[index].name, noble_knights[index].valor);
    } else {
        printf("Alas! No knight of that name can be found in the annals of valor.\n");
    }
    
    return 0;
}