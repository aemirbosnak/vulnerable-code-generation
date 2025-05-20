//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <string.h>

// This program reads in a string from the user and encrypts it using a unique C algorithm 
// that we made up! 

int main() {

    char user_input[100];
    printf("Hello! Please enter a string for encryption:\n");
    scanf("%s", user_input);

    // Let's first reverse the string
    int len = strlen(user_input);
    char encrypted_str1[len];
    for (int i = 0; i < len; i++) {
        encrypted_str1[i] = user_input[len-i-1];
    }
    encrypted_str1[len] = '\0';

    // Next, we'll convert all the vowels to their ascii value and switch them with the last letter
    char encrypted_str2[len];
    int vowel_count = 0;
    for (int i = 0; i < len; i++) {
        char c = encrypted_str1[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowel_count++;
            int ascii_val = (int) c;
            encrypted_str2[len-i-1] = (char) ascii_val;
        }
        else {
            encrypted_str2[i-vowel_count] = c;
        }
    }
    encrypted_str2[len] = '\0';
    
    // Finally, let's add an exclamation point to the end
    char encrypted_str3[len+2];
    for (int i = 0; i < len; i++) {
        encrypted_str3[i] = encrypted_str2[i];
    }
    encrypted_str3[len] = '!';
    encrypted_str3[len+1] = '\0';

    // Print the final encrypted string!
    printf("Here is your encrypted string:\n");
    printf("%s", encrypted_str3);

    return 0;
}