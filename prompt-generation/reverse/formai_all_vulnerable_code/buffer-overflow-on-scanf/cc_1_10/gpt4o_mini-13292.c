//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>
#include <stdint.h>

// Define bitwise flags
#define FLAG_A (1 << 0) // 0001
#define FLAG_B (1 << 1) // 0010
#define FLAG_C (1 << 2) // 0100
#define FLAG_D (1 << 3) // 1000

typedef struct {
    uint8_t flags; // Using an 8-bit value to store flags
} FlagManager;

// Function to set a flag
void set_flag(FlagManager *fm, uint8_t flag) {
    fm->flags |= flag;
}

// Function to clear a flag
void clear_flag(FlagManager *fm, uint8_t flag) {
    fm->flags &= ~flag;
}

// Function to toggle a flag
void toggle_flag(FlagManager *fm, uint8_t flag) {
    fm->flags ^= flag;
}

// Function to check if a flag is set
int is_flag_set(FlagManager *fm, uint8_t flag) {
    return (fm->flags & flag) != 0;
}

// Function to display current flags
void display_flags(FlagManager *fm) {
    printf("Current flags: 0b");
    for (int i = 7; i >= 0; i--) { // Print in binary format
        printf("%d", (fm->flags >> i) & 1);
    }
    printf("\n");
}

// Main function
int main() {
    FlagManager fm = {0}; // Initialize flags to 0
    
    int choice, flag;
    
    while (1) {
        printf("\nBitwise Flag Manager\n");
        printf("1. Set Flag\n");
        printf("2. Clear Flag\n");
        printf("3. Toggle Flag\n");
        printf("4. Check Flag\n");
        printf("5. Display Flags\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter flag to set (1: A, 2: B, 3: C, 4: D): ");
                scanf("%d", &flag);
                if (flag < 1 || flag > 4) {
                    printf("Invalid flag!\n");
                } else {
                    set_flag(&fm, (1 << (flag - 1)));
                    printf("Flag %d set.\n", flag);
                }
                break;

            case 2:
                printf("Enter flag to clear (1: A, 2: B, 3: C, 4: D): ");
                scanf("%d", &flag);
                if (flag < 1 || flag > 4) {
                    printf("Invalid flag!\n");
                } else {
                    clear_flag(&fm, (1 << (flag - 1)));
                    printf("Flag %d cleared.\n", flag);
                }
                break;

            case 3:
                printf("Enter flag to toggle (1: A, 2: B, 3: C, 4: D): ");
                scanf("%d", &flag);
                if (flag < 1 || flag > 4) {
                    printf("Invalid flag!\n");
                } else {
                    toggle_flag(&fm, (1 << (flag - 1)));
                    printf("Flag %d toggled.\n", flag);
                }
                break;

            case 4:
                printf("Enter flag to check (1: A, 2: B, 3: C, 4: D): ");
                scanf("%d", &flag);
                if (flag < 1 || flag > 4) {
                    printf("Invalid flag!\n");
                } else {
                    if (is_flag_set(&fm, (1 << (flag - 1)))) {
                        printf("Flag %d is set.\n", flag);
                    } else {
                        printf("Flag %d is not set.\n", flag);
                    }
                }
                break;

            case 5:
                display_flags(&fm);
                break;

            case 6:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}