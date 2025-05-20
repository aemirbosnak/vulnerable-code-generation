//FormAI DATASET v1.0 Category: Online Examination System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
  char name[50];
  int rollNo;
  int marks;
}s;

int main(){
  printf("Welcome to the Online Examination System!\n");
  printf("Enter your name: ");
  fgets(s.name,50,stdin);
  printf("\nEnter your roll number: ");
  scanf("%d",&s.rollNo);
  printf("\nHello %s, Your roll number is %d\n", s.name, s.rollNo);

  printf("The test consists of 10 multiple choice questions.");
  printf("\nEach question has 4 options and only one answer is correct.");
  printf("\nFor each correct answer, you will get 10 marks and for each wrong answer, 2 marks will be deducted.");
  printf("\nLet's begin the test!\n");

  int count=0;
  char ans;

  printf("\n1.What is the capital of India?\n");
  printf("a.New Delhi\tb.Chennai\nc.Mumbai\td.Kolkata\n");
  scanf(" %c",&ans);

  if(ans=='a'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n2.What is the currency of Japan?\n");
  printf("a.USD\tb.RMB\nc.Yen\td.Peso\n");
  scanf(" %c",&ans);

  if(ans=='c'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n3.Which is the largest continent in the world?\n");
  printf("a.Africa\tb.Asia\nc.Australia\td.Europe\n");
  scanf(" %c",&ans);

  if(ans=='b'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n4.What is the color of an apple?\n");
  printf("a.Yellow\tb.Green\nc.Red\td.Blue\n");
  scanf(" %c",&ans);

  if(ans=='c'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n5.Who is the founder of Microsoft?\n");
  printf("a.Steve Jobs\tb.Bill Clinton\nc.Bill Gates\td.Mark Zuckerberg\n");
  scanf(" %c",&ans);

  if(ans=='c'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n6.What is the largest organ in the human body?\n");
  printf("a.Liver\tb.Lungs\nc.Heart\td.Skin\n");
  scanf(" %c",&ans);

  if(ans=='d'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n7.What is the equivalent of 1 kilogram in grams?\n");
  printf("a.1000g\tb.500g\nc.750g\td.250g\n");
  scanf(" %c",&ans);

  if(ans=='a'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n8.Which country won the 2018 FIFA World Cup?\n");
  printf("a.Germany\tb.Argentina\nc.Brazil\td.France\n");
  scanf(" %c",&ans);

  if(ans=='d'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n9.Which planet in our Solar System is known as the Red Planet?\n");
  printf("a.Jupiter\tb.Venus\nc.Mars\td.Uranus\n");
  scanf(" %c",&ans);

  if(ans=='c'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\n10.Which is the largest airport in the world based on the area?\n");
  printf("a.Dubai International Airport\tb.John F. Kennedy International Airport\nc.Abu Dhabi International Airport\td.Beijing Daxing International Airport\n");
  scanf(" %c",&ans);

  if(ans=='a'){
      s.marks+=10;
      count++;
  }
  else{
      s.marks-=2;
  }

  printf("\nTotal marks: %d", s.marks);
  printf("\nNumber of correct answers: %d", count);
  printf("\nNumber of wrong answers: %d", 10-count);
  printf("\nThank you for taking the test, %s!", s.name);

  return 0;
}