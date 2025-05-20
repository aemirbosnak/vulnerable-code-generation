//FormAI DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>

// Function to display the instructions for the exam
void displayInstructions()
{
    printf("Welcome to the online exam system!\n\n");
    printf("Instructions:\n");
    printf("- There are 10 multiple choice questions.\n");
    printf("- For each question, choose the correct answer from the given options.\n");
    printf("- You will get 1 point for each correct answer and 0 points for each wrong answer.\n");
    printf("- You have 20 minutes to complete the exam.\n\n");
}

// Function to display the questions and get the user's answers
void takeExam()
{
    int score = 0; // Initialize user's score to 0
    
    // Array of questions and their choices
    char questions[][100] = {
        "What is the capital of India?\nA. New Delhi\nB. Mumbai\nC. Bangalore\nD. Chennai\n",
        "What is the largest continent by land area?\nA. North America\nB. Africa\nC. Asia\nD. South America\n",
        "Who is the current CEO of Microsoft?\nA. Satya Nadella\nB. Bill Gates\nC. Mark Zuckerberg\nD. Tim Cook\n",
        "What is the smallest country in the world by land area?\nA. Monaco\nB. Vatican City\nC. San Marino\nD. Liechtenstein\n",
        "What is the chemical symbol for gold?\nA. Go\nB. Au\nC. Gu\nD. Gl\n",
        "Which is the longest river in the world?\nA. Amazon\nB. Nile\nC. Mississippi\nD. Yangtze\n",
        "When was the first iPhone released?\nA. 2006\nB. 2007\nC. 2008\nD. 2009\n",
        "Who played the role of Harry Potter in the Harry Potter movie series?\nA. Tom Hanks\nB. Tom Cruise\nC. Daniel Radcliffe\nD. Robert Pattinson\n",
        "What is the capital of Australia?\nA. Sydney\nB. Brisbane\nC. Canberra\nD. Melbourne\n",
        "Which is the highest mountain in the world?\nA. Mount Everest\nB. Mount Kilimanjaro\nC. Mount Fuji\nD. Mount Olympus\n"
    };
    
    // Array of correct answers for the questions
    char answers[] = {'A', 'C', 'A', 'B', 'B', 'B', 'B', 'C', 'C', 'A'};
    
    // Loop through the questions and get the user's answers
    for (int i = 0; i < 10; i++)
    {
        char userChoice;
        
        printf("%s", questions[i]);
        scanf(" %c", &userChoice); // Get the user's answer
        
        if (userChoice == answers[i]) // Check if the answer is correct
            score++; // Increase user's score by 1 for a correct answer
    }
    
    printf("\nYour score is: %d", score); // Display user's score
}

int main()
{
    displayInstructions(); // Display the instructions for the exam
    takeExam(); // Take the exam
    
    return 0; // Return 0 to indicate successful execution of the program
}