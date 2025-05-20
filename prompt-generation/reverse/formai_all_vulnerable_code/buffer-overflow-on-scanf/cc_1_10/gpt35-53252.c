//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Define the periodic table
char periodic_table[] = "H He Li Be B C N O F Ne Na Mg Al Si P S Cl Ar K Ca Sc Ti V Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr Rb Sr Y Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I Xe Cs Ba La Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu Hf Ta W Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn Fr Ra Ac Th Pa U Np Pu Am Cm Bk Cf Es Fm Md No Lr Rf Db Sg Bh Hs Mt Ds Rg Cn Nh Fl Mc Lv Ts Og";

// Define the number of elements in the periodic table
int num_elements = 118;

// Define the number of questions for the quiz
int num_questions = 10;

// Define the number of threads to use
int num_threads = 2;

// Define the struct to pass arguments to the quiz thread
typedef struct {
    int start;
    int end;
} ThreadArg;

// Define the struct to store the user's answer to a question
typedef struct {
    int question_num;
    char user_answer[3];
} Answer;

// Define the global array to store the user's answers
Answer user_answers[10];

// Define the function to ask a question
void ask_question(int question_num) {
    // Choose a random element from the periodic table
    int idx = rand() % num_elements;
    char *element = strtok(periodic_table, " ");
    for (int i = 0; i < idx; i++) {
        element = strtok(NULL, " ");
    }

    // Print the question
    printf("Question %d: What is the symbol for %s?\n", question_num, element);

    // Get the user's answer
    scanf("%s", user_answers[question_num-1].user_answer);

    // Save the question number
    user_answers[question_num-1].question_num = question_num;
}

// Define the thread function for the quiz
void *quiz_thread(void *arg) {
    ThreadArg *thread_arg = (ThreadArg *)arg;
    int start = thread_arg->start;
    int end = thread_arg->end;

    for (int i = start; i <= end; i++) {
        ask_question(i);
    }

    pthread_exit(NULL);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Print instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions. Good luck!\n", num_questions);

    // Divide the questions evenly among the threads
    int questions_per_thread = num_questions / num_threads;

    // Create an array of threads
    pthread_t threads[num_threads];

    // Create an array of thread arguments
    ThreadArg thread_args[num_threads];

    // Create the threads and assign them their respective questions
    int thread_start = 1;
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].start = thread_start;
        thread_args[i].end = thread_start + questions_per_thread - 1;
        if (i == num_threads - 1) {
            thread_args[i].end = num_questions;
        }
        pthread_create(&threads[i], NULL, quiz_thread, (void *)&thread_args[i]);
        thread_start += questions_per_thread;
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the user's answers
    printf("\nYour answers:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", user_answers[i].question_num, user_answers[i].user_answer);
    }

    return 0;
}