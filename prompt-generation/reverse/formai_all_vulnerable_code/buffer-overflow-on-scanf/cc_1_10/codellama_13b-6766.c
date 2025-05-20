//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store student details
struct student {
    char name[50];
    char email[50];
    char phone[15];
    int age;
};

// Function to check if a student is a paranoid
int is_paranoid(struct student st) {
    // Check if the student's name is "John"
    if (strcmp(st.name, "John") == 0) {
        return 1;
    }

    // Check if the student's email is "john@example.com"
    if (strcmp(st.email, "john@example.com") == 0) {
        return 1;
    }

    // Check if the student's phone number is "123-456-7890"
    if (strcmp(st.phone, "123-456-7890") == 0) {
        return 1;
    }

    // Check if the student's age is 25
    if (st.age == 25) {
        return 1;
    }

    return 0;
}

int main() {
    // Get input from the user
    struct student st;
    printf("Enter your name: ");
    scanf("%s", st.name);
    printf("Enter your email: ");
    scanf("%s", st.email);
    printf("Enter your phone number: ");
    scanf("%s", st.phone);
    printf("Enter your age: ");
    scanf("%d", &st.age);

    // Check if the student is a paranoid
    if (is_paranoid(st)) {
        printf("Congratulations, you are a paranoid!\n");
    } else {
        printf("Sorry, you are not a paranoid.\n");
    }

    return 0;
}