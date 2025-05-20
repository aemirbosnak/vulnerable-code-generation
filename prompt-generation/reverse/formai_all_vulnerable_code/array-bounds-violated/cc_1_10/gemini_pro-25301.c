//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_number(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to generate a random fortune
char *generate_fortune() {
  // Array of possible fortunes
  char *fortunes[] = {
    "A beautiful, smart, and loving person will soon enter your life.",
    "A dubious friend may be an enemy in camouflage.",
    "A faithful friend is a strong defense.",
    "A friend asks only for your time not your money.",
    "A journey of a thousand miles begins with a single step.",
    "A kind word is like a spring day.",
    "A laugh is worth a thousand groans.",
    "A lifetime of happiness lies ahead of you.",
    "A new venture is on the horizon.",
    "A pleasant surprise is in store for you.",
    "A smooth sea never made a skilled sailor.",
    "A soft voice may be full of guile.",
    "A song can make the heart lighter.",
    "A wise old owl sat on an oak.",
    "All is well!",
    "All that glitters is not gold.",
    "Always be yourself, express yourself, have faith in yourself. Do not go out and look for a successful personality and duplicate it.",
    "Always remember that you are absolutely unique. Just like everyone else.",
    "As a wise man once said: 'I never forget a face, but in your case I'll make an exception.'",
    "Believe it can be done.",
    "But soft, what light through yonder window breaks?",
    "Do not follow where the path may lead. Go instead where there is no path and leave a trail.",
    "Do not let the behavior of others destroy your inner peace.",
    "Do not take life too seriously. You will never get out of it alive.",
    "Do not worry about the future, or what may not happen.",
    "Don't cry because it's over, smile because it happened.",
    "Even a happy life cannot be without a measure of darkness, and the word happy would lose its meaning if it were not balanced by sadness.",
    "Even the darkest nights will end and the sun will rise.",
    "Everything happens for a reason.",
    "Everything you can imagine is real.",
    "For every dark night, there's a brighter day.",
    "Fortune favors the bold.",
    "Friendship is the only cement that will hold the world together.",
    "Happiness can be found even in the darkest of times, if one only remembers to turn on the light.",
    "He who angers you conquers you.",
    "He who is contented is rich.",
    "I can resist everything except temptation.",
    "I hear and I forget. I see and I remember. I do and I understand.",
    "If a cluttered desk is a sign of a cluttered mind, of what, then, is an empty desk a sign?",
    "If opportunity doesn't knock, build a door.",
    "If the wind will not serve, take to the oars.",
    "If you can't fly then run, if you can't run then walk, if you can't walk then crawl, but whatever you do you have to keep moving forward.",
    "If you want to live a happy life, tie it to a goal, not to people or things.",
    "If you want to make your dreams come true, the first thing you have to do is wake up.",
    "In three words I can sum up everything I've learned about life: it goes on.",
    "It does not matter how slow you go so long as you do not stop.",
    "It is better to be a lion for a day than a sheep all your life.",
    "It is during our darkest moments that we must focus to see the light.",
    "It is not the years in your life that count. It is the life in your years.",
    "It is the unknown that attracts us and terrifies us at the same time.",
    "It is wise to direct your anger towards problems, not people; to focus your energies on answers, not excuses.",
    "It's not who you are underneath, it's what you do that defines you.",
    "Keep your face to the sunshine and you cannot see the shadow.",
    "Life is a journey, not a destination.",
    "Life is like a box of chocolates, you never know what you're gonna get.",
    "Life is like riding a bicycle. To keep your balance you must keep moving.",
    "Life is too short to be anything but happy.",
    "Live each day as if it were your last.",
    "Live in the sunshine, swim the sea, drink the wild air.",
    "May you always have a shell in your pocket and sand in your shoes.",
    "May you live long and prosper.",
    "May your days be filled with sunshine and your nights with sweet dreams.",
    "Never give up on a dream just because of the time it will take to accomplish it. The time will pass anyway.",
    "Never let the fear of striking out keep you from playing the game.",
    "Never underestimate the power of a kind word.",
    "No one can make you feel inferior without your consent.",
    "Nothing is impossible, the word itself says 'I'm possible!'",
    "Oh, the places you'll go!",
    "Old age is a shipwreck.",
    "Once you choose hope, anything's possible.",
    "Only those who dare to fail greatly can ever achieve greatly.",
    "Our lives are not our own. We are bound to others, past and present, and by each crime and every kindness, we birth our future.",
    "Peace begins with a smile.",
    "Remember that the happiest people are not those getting more, but those giving more.",
    "The best is yet to come.",
    "The greatest glory in living lies not in never falling, but in rising every time we fall.",
    "The journey of a thousand miles begins with a single step.",
    "The only person you are destined to become is the person you decide to be.",
    "The only true wisdom is in knowing you know nothing.",
    "The world is a book and those who do not travel read only one page.",
    "The world is full of nice people. If you can't find one, be one.",
    "There are far, far better things ahead than any we leave behind.",
    "There is no greater agony than bearing an untold story inside you.",
    "There is no one who lives who is not deformed in some way.",
    "There is only one happiness in life, to love and to be loved.",
    "They say a person needs just three things to be truly happy in this world: someone to love, something to do, and something to hope for.",
    "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment.",
    "To live is the rarest thing in the world. Most people exist, that is all.",
    "Today is the first day of the rest of your life.",
    "Tomorrow is another day.",
    "Travel makes a wise man better and a fool worse.",
    "Try to be a rainbow in someone's cloud.",
    "Twenty years from now you will be more disappointed by the things that you didn't do than by the ones you did do.",
    "We are all in the gutter, but some of us are looking at the stars.",
    "When life gives you lemons, make lemonade.",
    "When the going gets tough, the tough get going.",
    "Where there is love there is life.",
    "Whoever is happy will make others happy too.",
    "You can never cross the ocean until you have the courage to lose sight of the shore.",
    "You cannot always control what goes on outside. But you can always control what goes on inside.",
    "You do not find the happy life. You make it.",
    "You must do the things you think you cannot do.",
    "Your mind will answer most questions if you learn to relax and wait for the answer.",
    "Your time is limited, so don't waste it living someone else's life.",
    "You've gotta dance like there's nobody watching, love like you'll never be hurt, sing like there's nobody listening, and live like it's heaven on earth."
  };

  // Get a random index
  int index = random_number(0, sizeof(fortunes) / sizeof(char *));

  // Return the fortune at the random index
  return fortunes[index];
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random fortune
  char *fortune = generate_fortune();

  // Print the fortune
  printf("%s\n", fortune);

  return 0;
}