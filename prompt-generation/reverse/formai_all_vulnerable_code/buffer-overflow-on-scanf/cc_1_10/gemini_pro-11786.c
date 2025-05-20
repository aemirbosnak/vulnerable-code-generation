//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
/*
    Dr. Watson necessitates your assistance on a peculiar case.

    He suspects that the infamous Moriarty has devised an ingenious cipher to conceal his nefarious plans. The cipher operates upon a series of digits, masking their true values beneath a veil of deception.

    Dr. Watson has intercepted a cryptic message, believed to be Moriarty's latest machinations. However, he lacks the deductive prowess to decipher it.

    Your task, my dear Holmes, is to write a recursive program that unravels Moriarty's cipher, revealing the hidden digits that lie within.

    Moriarty's cipher employs a devious method to obscure each digit. He assigns a random offset to every digit, ranging from 0 to 9. To retrieve the original digit, one must subtract the offset from the masked digit. However, the offset itself is not directly observable.

    Fortunately, Moriarty has left subtle clues within the message. Each masked digit is followed by a corresponding "hint" digit. The hint digit is the sum of the masked digit and the offset.

    Equipped with this knowledge, you must embark on a recursive investigation, peeling back the layers of Moriarty's deception.

    Your program should:

    1. Read the intercepted message from Dr. Watson.
    2. Parse the message into a sequence of masked digits and hint digits.
    3. Employ recursion to decipher each masked digit by subtracting the offset (calculated as the difference between the hint digit and the masked digit).
    4. Unravel the true digits, revealing Moriarty's hidden plans.
    5. Present the deciphered message to Dr. Watson, aiding him in his quest to thwart Moriarty's sinister schemes.

    Proceed with caution, Holmes. Moriarty is a cunning adversary, and his cipher may test the limits of your deductive abilities.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to decipher a single masked digit
int decipher_digit(int masked_digit, int hint_digit) {
    return hint_digit - masked_digit;
}

// Function to decipher the entire message recursively
void decipher_message(int *masked_digits, int *hint_digits, int n) {
    if (n == 0) {  // Base case: No digits left to decipher
        return;
    }

    // Decipher the current masked digit
    int deciphered_digit = decipher_digit(masked_digits[n - 1], hint_digits[n - 1]);

    // Print the deciphered digit
    printf("%d", deciphered_digit);

    // Recursively decipher the remaining digits
    decipher_message(masked_digits, hint_digits, n - 1);
}

int main() {
    // Read the intercepted message from Dr. Watson
    int n;  // Number of digits in the message
    printf("Dr. Watson, how many digits are in the intercepted message? ");
    scanf("%d", &n);

    int masked_digits[n];  // Array to store the masked digits
    int hint_digits[n];    // Array to store the hint digits
    printf("Please enter the masked digits followed by their corresponding hint digits (e.g. 2 4):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &masked_digits[i], &hint_digits[i]);
    }

    // Decipher the message
    printf("My dear Watson, the deciphered message is: ");
    decipher_message(masked_digits, hint_digits, n);
    printf("\n");

    return 0;
}