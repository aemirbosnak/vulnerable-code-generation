//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int age;
  float height, weight, bmi;

  printf("Enter your age: ");
  scanf("%d", &age);

  printf("Enter your height in meters: ");
  scanf("%f", &height);

  printf("Enter your weight in kilograms: ");
  scanf("%f", &weight);

  bmi = weight / (height * height);
  printf("Your BMI is %.2f\n", bmi);

  if (age < 18){
    printf("You are too young to use this fitness tracker.\n");
    exit(0);
  }

  int goal;
  printf("What is your fitness goal?\n");
  printf("[1] Lose weight\n");
  printf("[2] Build muscle\n");
  printf("[3] Maintain current weight\n");
  scanf("%d", &goal);

  if (goal == 1){
    printf("Ah, losing weight... a hard journey, yet a worthy one!\n");
    printf("But soft, what workout shall we follow?\n");

    printf("[1]Cardiovascular workout: Running, cycling, or swimming.\n");
    printf("[2]Strength training: Resistance training with weights.\n");
    printf("[3]Yoga workout: Peaceful while challenging practice to tone the body.\n");
    int workout;
    scanf("%d", &workout);
    switch(workout){
      case 1:
        printf("(Morning sunlight enters the room through the fainest of cracks)\n");
        printf("Romeo: Hark, what is that I hear?\n");
        printf("Benvolio: That, dear Romeo, is the sound of the morning birds.\n");
        printf("Romeo: Nay, sweet Benvolio, it is a call to the road, to run, to break our sweat for weight loss!\n");
        printf("Benvolio: (smirks) Longer runs in the morning may indeed perform wonders to one's health!\n");
        break;
      case 2:
        printf("(A weight hits the floor)\n");
        printf("Romeo: To become stronger we must lift, hark on the tips of our toes, gritting our teeth as we life the weight.\n");
        printf("Benvolio: (wincing) But dear Romeo, the pain...?!\n");
        printf("Romeo: Nay, the burn is but the only way to gain!\n");
        break;
      case 3:
        printf("(Soft music plays throughout the room)\n");
        printf("Romeo: To practice yoga invigorates the body and calms the mind, which we must strive to do in the tumult of life.\n");
        printf("Benvolio: (mimicking) Namaste, Romeo.\n");
        printf("Romeo: (rolls his eyes) And peace be upon thee, Benvolio. \n");
        break;
      default:
        printf("Invalid workout choice. Goodbye!\n");
        exit(0);
    }
  } else if (goal == 2){
    printf("Ah, building muscles... a noble endeavor indeed!\n");
    printf("But soft, what workout shall we follow?\n");

    printf("[1]High-intensity interval training: A time-efficient way to increase muscular strength\n");
    printf("[2]Resistance training: Lifting weights with the aim of increasing strength and muscle mass.\n");
    printf("[3]Bodyweight training: Zero equipment yet an effective way to build muscle and strength with moves like push-ups and squats.\n");

    int workout;
    scanf("%d", &workout);

    switch(workout){
      case 1:
        printf("(Labored breathing echoes in the weight room)\n");
        printf("Romeo: We must push through the pain, the discomfort, for we shall come out stronger than before!\n");
        printf("Benvolio: (grunting) Aye, the burn is but temporary but the gains are everlasting!\n");
        break;
      case 2:
        printf("(Dumbbells clank against the floor)\n");
        printf("Romeo: To lift is to overcome oneself, which is a victory second to none.\n");
        printf("Benvolio: (grinning) And what sweet victory it is!\n");
        break;
      case 3:
        printf("(A still silence rests in the room)\n");
        printf("Romeo: To use the body as a source of strength is to tap into one's true potential.\n");
        printf("Benvolio: (nodding) Not only that, it's space and equipment friendly!\n");
        break;
      default:
        printf("Invalid workout choice. Goodbye!\n");
        exit(0);
    }
  } else if (goal == 3){
    printf("Ah, maintaining your current weight... wise choice!\n");
    printf("But soft, what workout shall we follow?\n");

    printf("[1]Pilates: Lengthening and toning muscles while enhancing flexibility and posture.\n");
    printf("[2]Swimming: An all-around way to tone muscles, reduce weight, and improve cardiovascular health.\n");
    printf("[3]Hiking: Being in nature while getting a good workout. \n");

    int workout;
    scanf("%d", &workout);

    switch(workout){
      case 1:
        printf("(The sound of breathing and the rolling of a mat.)\n");
        printf("Romeo: We are but leaves breathed by this art of movement, balance, and grace.\n");
        printf("Benvolio: (with a satisfaction) It's like yoga but with a tougher twist! It's perfect!\n");
        break;
      case 2:
        printf("(The sound of splashes)\n");
        printf("Romeo: Swimming, where our body is weightless and one with the water, and all we have to do is make our way to the other side.\n");
        printf("Benvolio: (grinning) And watch through our goggles as all our fat melts away!\n");
        break;
      case 3:
        printf("(A sound of leaves being rustled)\n");
        printf("Romeo: The terrain is new yet the body moves constantly, and that is the beauty of the hike.\n");
        printf("Benvolio: (gasping) It's like experiencing a story while getting a workout!\n");
        break;
      default:
        printf("Invalid workout choice. Goodbye!\n");
        exit(0);
    }
  } else {
    printf("Invalid goal choice. Goodbye!\n");
    exit(0);
  }

  printf("Enter your workout duration in minutes: ");
  int duration;
  scanf("%d", &duration);

  printf("Good job! You have successfully completed a %d-minute workout!\n", duration);

  return 0;
}