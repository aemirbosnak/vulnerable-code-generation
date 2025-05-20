//FormAI DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char name[50], job[50], street[50], city[50];
    char full_address[150];
    
    printf("Input your name, punk: ");
    scanf("%s", name);
    
    printf("What do you do for a living? ");
    scanf("%s", job);
    
    printf("What street do you reside in? ");
    scanf("%s", street);
    
    printf("What city do you call home? ");
    scanf("%s", city);
    
    printf("\nProcessing data...\n\n");
    
    // Concatenate the strings to create a full address
    strcat(full_address, name);
    strcat(full_address, ", the ");
    strcat(full_address, job);
    strcat(full_address, ", resides in ");
    strcat(full_address, street);
    strcat(full_address, " street, ");
    strcat(full_address, city);
    strcat(full_address, ".");
    
    printf("Your full address is:\n%s", full_address);
    
    // Convert the full address to cyberpunk style
    for (int i = 0; i < strlen(full_address); i++) {
        if (full_address[i] == ' ') {
            full_address[i] = '-';
        } else if (full_address[i] == ',') {
            full_address[i] = '/';
        } else if (full_address[i] == '.') {
            full_address[i] = '|';
        } else if (full_address[i] == '-') {
            full_address[i] = '_';
        } else if (full_address[i] == '/') {
            full_address[i] = '|';
        }
        
        if (i % 2 == 0) {
            full_address[i] = toupper(full_address[i]);
        }
    }
    
    printf("\nYour cyberpunk address is:\n%s", full_address);
    
    return 0;
}