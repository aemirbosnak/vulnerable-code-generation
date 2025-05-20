//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Question {
  char question[512];
  char options[4][128];
  int correct_answer;
} Question;

typedef struct Student {
  char name[128];
  int score;
} Student;

Question questions[] = {
  {
    "What is the capital of France?",
    {
      "Paris",
      "London",
      "Berlin",
      "Rome"
    },
    0
  },
  {
    "What is the largest ocean in the world?",
    {
      "Pacific Ocean",
      "Atlantic Ocean",
      "Indian Ocean",
      "Arctic Ocean"
    },
    0
  },
  {
    "What is the most common element in the universe?",
    {
      "Hydrogen",
      "Helium",
      "Carbon",
      "Oxygen"
    },
    0
  },
  {
    "What is the speed of light?",
    {
      "299,792,458 meters per second",
      "186,282 miles per second",
      "300,000 kilometers per second",
      "1 billion miles per hour"
    },
    0
  },
  {
    "What is the name of the largest moon in the solar system?",
    {
      "Ganymede",
      "Titan",
      "Callisto",
      "Io"
    },
    0
  }
};

Student students[] = {
  {
    "John Doe",
    0
  },
  {
    "Jane Smith",
    0
  },
  {
    "Bob Jones",
    0
  },
  {
    "Alice Brown",
    0
  },
  {
    "Tom Green",
    0
  }
};

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Shuffle the questions
  for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
    int j = rand() % (sizeof(questions) / sizeof(Question));
    Question temp = questions[i];
    questions[i] = questions[j];
    questions[j] = temp;
  }

  // Shuffle the students
  for (int i = 0; i < sizeof(students) / sizeof(Student); i++) {
    int j = rand() % (sizeof(students) / sizeof(Student));
    Student temp = students[i];
    students[i] = students[j];
    students[j] = temp;
  }

  // Start the exam
  for (int i = 0; i < sizeof(students) / sizeof(Student); i++) {
    printf("Student %s\n", students[i].name);
    for (int j = 0; j < sizeof(questions) / sizeof(Question); j++) {
      printf("%s\n", questions[j].question);
      for (int k = 0; k < 4; k++) {
        printf("%d. %s\n", k + 1, questions[j].options[k]);
      }
      int answer;
      do {
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
      } while (answer < 1 || answer > 4);
      if (answer == questions[j].correct_answer + 1) {
        students[i].score++;
      }
    }
    printf("Your score is %d out of %d\n", students[i].score, sizeof(questions) / sizeof(Question));
  }

  return 0;
}