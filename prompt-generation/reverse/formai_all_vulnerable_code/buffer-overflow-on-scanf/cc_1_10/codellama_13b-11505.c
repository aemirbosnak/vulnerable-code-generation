//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: protected
int main() {
  int score = 0;
  int total_questions = 10;
  int correct_answers = 0;

  for (int i = 0; i < total_questions; i++) {
    int question_number = i + 1;
    printf("Question %d: ", question_number);
    int user_answer = get_user_answer();
    int correct_answer = get_correct_answer(question_number);
    if (user_answer == correct_answer) {
      correct_answers++;
      printf("Correct!\n");
    } else {
      printf("Wrong. The correct answer is %d.\n", correct_answer);
    }
  }

  score = (correct_answers / total_questions) * 100;
  printf("Your score is %d out of 100.\n", score);

  return 0;
}

int get_user_answer() {
  int user_answer;
  scanf("%d", &user_answer);
  return user_answer;
}

int get_correct_answer(int question_number) {
  int correct_answer;
  if (question_number == 1) {
    correct_answer = 42;
  } else if (question_number == 2) {
    correct_answer = 100;
  } else if (question_number == 3) {
    correct_answer = 15;
  } else if (question_number == 4) {
    correct_answer = 20;
  } else if (question_number == 5) {
    correct_answer = 10;
  } else if (question_number == 6) {
    correct_answer = 12;
  } else if (question_number == 7) {
    correct_answer = 15;
  } else if (question_number == 8) {
    correct_answer = 20;
  } else if (question_number == 9) {
    correct_answer = 25;
  } else if (question_number == 10) {
    correct_answer = 30;
  }
  return correct_answer;
}