//FormAI DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ans, user_ans;
    int score = 0;
    srand(time(NULL));
    printf("****************C ONLINE EXAMINATION SYSTEM*****************\n");
    printf("This exam will test your knowledge on C programming language.\n");
    printf("There are 10 questions in the exam, each question carries 10 marks.\n");
    printf("Good luck!\n");
    
    for (int i=1; i<=10; i++) {
        ans = rand() % 4 + 1;
        
        printf("\nQuestion %d:\n", i);
        printf("What is the output of the following code snippet?\n");
        
        switch (ans) {
            case 1:
                printf("#include <stdio.h>\nint main() {\n    printf(\"Hello, world!\\n\");\n    return 0;\n}");
                if (fgets(user_ans, 10, stdin) == NULL) exit(0);
                if (strcmp(user_ans, "Hello, world!") == 0) {
                    printf("Correct!\n");
                    score += 10;
                }
                else {
                    printf("Incorrect!\n");
                    printf("The answer is Hello, world!\n");
                }
                break;
                
            case 2:
                printf("#include <stdio.h>\nint main() {\n    int sum = 0;\n    for (int i=1; i<=10; i++) {\n        sum += i;\n    }\n    printf(\"Sum of first 10 natural numbers is: %d\\n\", sum);\n    return 0;\n}");
                if (fgets(user_ans, 10, stdin) == NULL) exit(0);
                if (strcmp(user_ans, "Sum of first 10 natural numbers is: 55") == 0) {
                    printf("Correct!\n");
                    score += 10;
                }
                else {
                    printf("Incorrect!\n");
                    printf("The answer is Sum of first 10 natural numbers is: 55\n");
                }
                break;
                
            case 3:
                printf("#include <stdio.h>\nint main() {\n    int num = 5;\n    if (num % 2 == 0) {\n        printf(\"%d is even\\n\", num);\n    }\n    else {\n        printf(\"%d is odd\\n\", num);\n    }\n    return 0;\n}");
                if (fgets(user_ans, 10, stdin) == NULL) exit(0);
                if (strcmp(user_ans, "5 is odd") == 0) {
                    printf("Correct!\n");
                    score += 10;
                }
                else {
                    printf("Incorrect!\n");
                    printf("The answer is 5 is odd\n");
                }
                break;
                
            case 4:
                printf("#include <stdio.h>\nint main() {\n    int a = 5, b = 3, c;\n    c = a + b;\n    printf(\"%d + %d = %d\\n\", a, b, c);\n    return 0;\n}");
                if (fgets(user_ans, 10, stdin) == NULL) exit(0);
                if (strcmp(user_ans, "5 + 3 = 8") == 0) {
                    printf("Correct!\n");
                    score += 10;
                }
                else {
                    printf("Incorrect!\n");
                    printf("The answer is 5 + 3 = 8\n");
                }
                break;
        }
    }
    
    printf("\nThank you for taking the exam.\n");
    printf("Your score is %d out of 100.\n", score);
    
    return 0;
}