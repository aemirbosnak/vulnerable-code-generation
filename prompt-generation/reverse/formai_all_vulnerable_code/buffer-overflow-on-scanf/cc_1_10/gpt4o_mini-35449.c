//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Function to print the binary representation of a number
void print_binary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1U << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' '); // Space every 4 bits for readability
    }
    putchar('\n');
}

// Function to demonstrate various bitwise operations
void bitwise_operations_demo(unsigned int a, unsigned int b) {
    printf("Original Numbers:\n");
    printf("A: %u --> Binary: ", a);
    print_binary(a);
    printf("B: %u --> Binary: ", b);
    print_binary(b);

    unsigned int and_result = a & b;
    printf("A & B = %u --> Binary: ", and_result);
    print_binary(and_result);
    
    unsigned int or_result = a | b;
    printf("A | B = %u --> Binary: ", or_result);
    print_binary(or_result);
    
    unsigned int xor_result = a ^ b;
    printf("A ^ B = %u --> Binary: ", xor_result);
    print_binary(xor_result);
    
    unsigned int not_a = ~a;
    printf("~A = %u --> Binary: ", not_a);
    print_binary(not_a);
    
    unsigned int not_b = ~b;
    printf("~B = %u --> Binary: ", not_b);
    print_binary(not_b);
    
    unsigned int left_shift_a = a << 1;
    printf("A << 1 = %u --> Binary: ", left_shift_a);
    print_binary(left_shift_a);
    
    unsigned int right_shift_a = a >> 1;
    printf("A >> 1 = %u --> Binary: ", right_shift_a);
    print_binary(right_shift_a);
    
    unsigned int left_shift_b = b << 1;
    printf("B << 1 = %u --> Binary: ", left_shift_b);
    print_binary(left_shift_b);
    
    unsigned int right_shift_b = b >> 1;
    printf("B >> 1 = %u --> Binary: ", right_shift_b);
    print_binary(right_shift_b);
}

// Function to read a number from the user
unsigned int read_number(const char *prompt) {
    unsigned int num;
    printf("%s", prompt);
    scanf("%u", &num);
    return num;
}

// Main function, the heart of the program, where the magic happens
int main() {
    printf("******************************************\n");
    printf("*          Welcome to Bitwise Land!     *\n");
    printf("******************************************\n");

    unsigned int a = read_number("Enter the first number (A): ");
    unsigned int b = read_number("Enter the second number (B): ");
    
    bitwise_operations_demo(a, b);
    
    printf("******************************************\n");
    printf("*   Explore the enigmatic Bitwise realm! *\n");
    printf("******************************************\n");
    
    printf("Unleash your creativity! Let's play some games with these numbers!\n");

    unsigned int game_choice;
    while (1) {
        printf("Choose a game:\n");
        printf("1. Infinity AND\n");
        printf("2. Mystic OR\n");
        printf("3. Legendary XOR\n");
        printf("4. Enigma NOT\n");
        printf("5. Shift Your Destiny (Left)\n");
        printf("6. Shift Your Destiny (Right)\n");
        printf("7. Exit the Bitwise Realm\n");
        printf("Enter your choice: ");
        scanf("%u", &game_choice);

        switch(game_choice) {
            case 1:
                printf("Let the Infinity AND game begin!\n");
                print_binary(a & b);
                break;
            case 2:
                printf("Enter a new number for Mystic OR: ");
                a = read_number("A new A: ");
                printf("Final Result: ");
                print_binary(a | b);
                break;
            case 3:
                printf("Legendary XOR is upon us!\n");
                print_binary(a ^ b);
                break;
            case 4:
                printf("Embrace the power of NOT!\n");
                printf("~A: ");
                print_binary(~a);
                break;
            case 5:
                printf("Left shifting can change destinies...\n");
                printf("Enter how many positions to shift (1-31): ");
                unsigned int shift;
                scanf("%u", &shift);
                printf("Final Result after shifting A: ");
                print_binary(a << shift);
                break;
            case 6:
                printf("Right shifting, a bittersweet farewell...\n");
                printf("Enter how many positions to shift (1-31): ");
                scanf("%u", &shift);
                printf("Final Result after shifting A: ");
                print_binary(a >> shift);
                break;
            case 7:
                printf("Exiting the Bitwise Realm! Return when you seek tough challenges!\n");
                exit(0);
            default:
                printf("Wander not off the path, choose wisely!\n");
        }
    }
    
    return 0;
}