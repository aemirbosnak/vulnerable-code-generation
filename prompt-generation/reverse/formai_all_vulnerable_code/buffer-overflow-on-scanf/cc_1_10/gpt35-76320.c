//FormAI DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct question {
    char ques[300];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int ans;
};

void display_instructions() {
    printf("Welcome to the Online Examination System!\n\n");
    printf("Instructions:\n1. There will be 5 multiple-choice questions.\n");
    printf("2. Choose the best answer out of the given options.\n");
    printf("3. Each question carries 2 marks.\n");
    printf("4. There is no negative marking.\n5. Press enter to start the exam.\n\n");
    getchar();
}

int take_test() {
    int score = 0;
    struct question quiz[5] = {
        {
            "What is the capital of India?",
            "Mumbai",
            "Delhi",
            "Chennai",
            "Kolkata",
            2
        },
        {
            "What is the national animal of India?",
            "Elephant",
            "Tiger",
            "Lion",
            "Deer",
            2
        },
        {
            "What is the currency of Japan?",
            "Yen",
            "Rupees",
            "Dollar",
            "Euro",
            1
        },
        {
            "Who is the founder of Google?",
            "Steve Jobs",
            "Larry Page",
            "Bill Gates",
            "Mark Zuckerberg",
            2
        },
        {
            "Who is known as the father of Indian Constitution?",
            "B.R. Ambedkar",
            "Mahatma Gandhi",
            "Jawaharlal Nehru",
            "Sardar Vallabhbhai Patel",
            1
        }
    };
    printf("Your test is about to start:\n\n");
    for (int i=0; i<5; i++) {
        printf("%d. %s\n",i+1,quiz[i].ques);
        printf("1. %s\n",quiz[i].option1);
        printf("2. %s\n",quiz[i].option2);
        printf("3. %s\n",quiz[i].option3);
        printf("4. %s\n\n",quiz[i].option4);
        int answer;
        do {
            printf("Enter answer (1-4): ");
            scanf("%d",&answer);
            getchar();
            if (answer<1 || answer>4) {
                printf("Invalid answer. Please try again.\n");
            }
        } while (answer<1 || answer>4);
        if (answer == quiz[i].ans) {
            printf("Correct answer!\n");
            score += 2;
        } else {
            printf("Wrong answer.\n");
        }
        printf("Press enter to continue.\n");
        getchar();
    }
    printf("Your score is: %d out of 10.\n",score);
    return score;
}

int main() {
    char name[50];
    printf("Enter your name: ");
    fgets(name,sizeof(name),stdin);
    printf("Hello %s",name);
    display_instructions();
    int score = take_test();
    if (score>=8) {
        printf("Congratulations! You passed the exam.\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }
    printf("Thanks for using our Online Examination System!\n");
    return 0;
}