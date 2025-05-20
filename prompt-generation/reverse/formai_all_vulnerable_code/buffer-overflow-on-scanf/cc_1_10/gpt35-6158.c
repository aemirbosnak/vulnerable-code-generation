//FormAI DATASET v1.0 Category: Online Examination System ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Struct to hold student data
struct student{
    char name[50];
    char roll_no[20];
    int score;
};

// Function declaration
void welcome_screen();
void instructions();
void start_exam();
void generate_questions();
void evaluate_exam();
void save_score(struct student);

int main(){

    welcome_screen(); // Display welcome screen
    instructions();   // Display exam instructions
    start_exam();     // Start the exam
    evaluate_exam();  // Evaluate the exam

    return 0;
}

// Function to display the welcome message
void welcome_screen(){
    printf("\t\tWelcome to the Online Examination System\n\n");
}

// Function to display the instructions
void instructions(){
    printf("Instructions:\n");
    printf("1. This is a multiple-choice exam consisting of 20 questions.\n");
    printf("2. Each question has only one correct answer.\n");
    printf("3. Each correct answer will be awarded 5 marks.\n");
    printf("4. There is no negative marking for incorrect answers.\n");
    printf("5. You have to choose the most appropriate answer among the given options.\n\n");
}

// Function to start the exam
void start_exam(){
    printf("Exam starts now...\n\n");
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("Please enter your roll number: ");
    char roll_no[20];
    scanf("%s", roll_no);
    printf("\n");

    // Save student data
    struct student s;
    strcpy(s.name, name);
    strcpy(s.roll_no, roll_no);
    s.score = 0;
    save_score(s);

    // Generate the questions
    generate_questions();
}

// Function to generate the questions
void generate_questions(){
    srand(time(NULL)); // Initialize random seed

    char *questions[] = {
        "1. What is the capital of India?\n(a) Mumbai\n(b) New Delhi\n(c) Kolkata\n(d) Bangalore\n",
        "2. Which planet is known as the red planet?\n(a) Earth\n(b) Jupiter\n(c) Mars\n(d) Mercury\n",
        "3. Who discovered the theory of relativity?\n(a) Isaac Newton\n(b) Albert Einstein\n(c) Galileo Galilei\n(d) Pythagoras\n",
        "4. What is the largest organ in the human body?\n(a) Heart\n(b) Brain\n(c) Liver\n(d) Skin\n",
        "5. Who wrote the famous Romeo and Juliet?\n(a) Charles Dickens\n(b) William Shakespeare\n(c) Jane Austen\n(d) Mark Twain\n",
        "6. Which is the largest animal in the world?\n(a) Blue Whale\n(b) Elephant\n(c) Giraffe\n(d) Crocodile\n",
        "7. Which country is famous for kangaroos?\n(a) Spain\n(b) Australia\n(c) India\n(d) Canada\n",
        "8. Which city is known as the pink city of India?\n(a) Agra\n(b) Jaipur\n(c) Delhi\n(d) Kolkata\n",
        "9. Which is the highest mountain peak in the world?\n(a) Mount Everest\n(b) K2\n(c) Kangchenjunga\n(d) Lhotse\n",
        "10. What is the national animal of India?\n(a) Tiger\n(b) Elephant\n(c) Lion\n(d) Leopard\n",
        "11. What is the national bird of India?\n(a) Peacock\n(b) Crow\n(c) Sparrow\n(d) Pigeon\n",
        "12. Who is the CEO of Microsoft Corporation?\n(a) Steve Ballmer\n(b) Satya Nadella\n(c) Sundar Pichai\n(d) Mark Zuckerberg\n",
        "13. Which country invented the game of chess?\n(a) China\n(b) Japan\n(c) India\n(d) Egypt\n",
        "14. Which planet is known as the blue planet?\n(a) Earth\n(b) Neptune\n(c) Jupiter\n(d) Saturn\n",
        "15. Who directed the movie Titanic?\n(a) James Cameron\n(b) Christopher Nolan\n(c) Steven Spielberg\n(d) Quentin Tarantino\n",
        "16. Which is the highest waterfall in the world?\n(a) Angel Falls\n(b) Niagara Falls\n(c) Victoria Falls\n(d) Iguazu Falls\n",
        "17. Who discovered the law of gravity?\n(a) Isaac Newton\n(b) Albert Einstein\n(c) Galileo Galilei\n(d) Pythagoras\n",
        "18. Which country is the largest producer of coffee in the world?\n(a) India\n(b) Brazil\n(c) China\n(d) Sri Lanka\n",
        "19. Which is the largest ocean in the world?\n(a) Arctic Ocean\n(b) Indian Ocean\n(c) Pacific Ocean\n(d) Atlantic Ocean\n",
        "20. Who is the founder of Facebook?\n(a) Bill Gates\n(b) Mark Zuckerberg\n(c) Larry Page\n(d) Sergey Brin\n"
    };

    char *answers[] = {
        "b",
        "c",
        "b",
        "d",
        "b",
        "a",
        "b",
        "b",
        "a",
        "a",
        "a",
        "b",
        "c",
        "a",
        "a",
        "a",
        "b",
        "b",
        "c",
        "b"
    };

    char response[20];
    int score = 0;
    for(int i=0; i<20; i++){
        printf("%s", questions[i]);
        printf("Enter your answer: ");
        scanf("%s", response);
        if(strcmp(response, answers[i]) == 0){
            printf("Correct!\n\n");
            score += 5;
        }
        else{
            printf("Incorrect!\n\n");
        }
    }

    // Save score
    struct student s;
    strcpy(s.name, "");
    strcpy(s.roll_no, "");
    s.score = score;
    save_score(s);
}

// Function to evaluate the exam
void evaluate_exam(){
    struct student s;
    FILE *fp;
    fp = fopen("scores.dat", "rb");
    if(fp == NULL){
        printf("Error reading file\n");
        exit(1);
    }

    printf("\nExam results:\n");
    printf("Name\tRoll No.\tScore\n");
    while(fread(&s, sizeof(s), 1, fp)){
        printf("%s\t%s\t\t%d\n", s.name, s.roll_no, s.score);
    }
    fclose(fp);
}

// Function to save the score
void save_score(struct student s){
    FILE *fp;
    fp = fopen("scores.dat", "ab");
    if(fp == NULL){
        printf("Error saving file\n");
        exit(1);
    }
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}