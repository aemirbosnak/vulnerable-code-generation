//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LOVE_EXPRESSIONS 100

typedef struct {
    char name[50];
    char love_letter[256];
} Lover;

void write_love_letter(Lover *lover) {
    snprintf(lover->love_letter, sizeof(lover->love_letter),
             "Dearest %s,\n\n"
             "From the first moment we met, you captured my heart. "
             "Each day without you feels like an eternity, "
             "and each moment spent together is a cherished memory.\n"
             "You are the sun to my sky, the moon to my night, "
             "and the stars that guide my dreams. Your laughter is music to my ears, "
             "and your smile ignites a fire in my soul.\n\n"
             "Forever yours,\nYour secret admirer.",
             lover->name);
}

void print_love_letter(const Lover *lover) {
    printf("%s\n", lover->love_letter);
}

void serenade(Lover *lovers, int count) {
    for (int i = 0; i < count; i++) {
        printf("Serenading %s...\n", lovers[i].name);
        usleep(1000000); // a gentle pause of a second
        write_love_letter(&lovers[i]);
        print_love_letter(&lovers[i]);
        printf("\n");
    }
}

int main() {
    int lover_count;
    printf("Enter the number of lovers: ");
    scanf("%d", &lover_count);
    
    if (lover_count > MAX_LOVE_EXPRESSIONS) {
        printf("Maximum number of lovers is %d. Please try again.\n", MAX_LOVE_EXPRESSIONS);
        return 1;
    }
    
    Lover *lovers = (Lover *)malloc(lover_count * sizeof(Lover));
    if (lovers == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    for (int i = 0; i < lover_count; i++) {
        printf("Enter the name of lover %d: ", i + 1);
        scanf("%s", lovers[i].name);
    }
    
    printf("\nA serenade for your lovers...\n\n");
    serenade(lovers, lover_count);
    
    printf("Thank you for using the Love Serenade Program!\n");
    
    free(lovers);
    return 0;
}