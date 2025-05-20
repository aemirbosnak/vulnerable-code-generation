//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORTUNES_COUNT 100

const char *fortunes[] = {
    "Your riches are like a garden, full of blossoming flowers.",
    "Your dreams are like stars, forever twinkling in the night sky.",
    "Your heart is like a pearl, pure and radiant.",
    "Your laughter is like music, a melody that brings joy to all who hear it.",
    "Your friendship is like a warm embrace, a comfort in times of need.",
    "Your kindness is like the sun, shining brightly on those around you.",
    "Your wisdom is like a river, flowing gently and carrying with it knowledge and understanding.",
    "Your spirit is like a bird, soaring high above the clouds.",
    "Your future is like a rainbow, filled with endless possibilities.",
    "Your love is like a gentle breeze, whispering sweet nothings in your ear.",
    "Your passion is like a fire, burning brightly and illuminating your path.",
    "Your creativity is like a canvas, filled with vibrant colors and endless possibilities.",
    "Your humor is like a balm, healing the wounds of others.",
    "Your resilience is like a rock, weathering the storms of life with grace.",
    "Your adaptability is like a chameleon, blending seamlessly into any environment.",
    "Your determination is like a bull, charging forward with unstoppable force.",
    "Your generosity is like a waterfall, flowing freely and benefiting all who come near.",
    "Your compassion is like a mother's embrace, nurturing and comforting those in need.",
    "Your empathy is like a mirror, reflecting the emotions of others with clarity and understanding.",
    "Your intuition is like a compass, guiding you through the labyrinth of life.",
    "Your loyalty is like a shield, protecting those you love from harm.",
    "Your integrity is like a lighthouse, shining a beacon of morality in a world of darkness.",
    "Your courage is like a lion, roaring defiance in the face of adversity.",
    "Your strength is like an oak tree, standing tall and unyielding against the winds of fate.",
    "Your beauty is like a sunrise, illuminating the world with its warm glow.",
    "Your spirit is like a butterfly, fluttering through life with grace and elegance.",
    "Your mind is like a library, filled with endless knowledge and wisdom.",
    "Your heart is like a garden, blooming with love and kindness.",
    "Your smile is like a ray of sunshine, brightening the day of everyone you meet.",
    "Your laughter is like music, bringing joy to all who hear it.",
    "Your friendship is like a treasure, a precious gift that enriches your life.",
    "Your presence is like a warm embrace, comforting and supportive.",
    "Your wisdom is like a guiding star, illuminating the path you should take.",
    "Your strength is like a mighty oak, unwavering in the face of adversity.",
    "Your courage is like a blazing fire, burning brightly in the face of danger.",
    "Your compassion is like a gentle breeze, soothing the wounds of those in need.",
    "Your love is like a warm blanket, enveloping you in comfort and security.",
    "Your spirit is like a soaring eagle, reaching for the heights of success.",
    "Your determination is like a river, flowing relentlessly towards your goals.",
    "Your resilience is like a rubber band, bouncing back from setbacks with renewed strength.",
    "Your adaptability is like a chameleon, blending seamlessly into any situation.",
    "Your humor is like a ray of sunshine, brightening even the darkest of days.",
    "Your creativity is like a paintbrush, painting vibrant colors on the canvas of life.",
    "Your imagination is like a soaring bird, taking you to worlds unknown.",
    "Your intuition is like a whisper, guiding you down the right path.",
    "Your loyalty is like a rock, unwavering in the face of adversity.",
    "Your integrity is like a compass, pointing you towards the true north of morality.",
    "Your courage is like a lion's roar, echoing through the challenges of life.",
    "Your strength is like an unbreakable chain, supporting you through every obstacle.",
    "Your beauty is like a blooming flower, radiating joy and serenity.",
    "Your spirit is like a gentle breeze, carrying you through life's gentle embrace.",
    "Your mind is like a sharp sword, cutting through the fog of confusion.",
    "Your heart is like a golden key, unlocking the treasures of love and happiness.",
    "Your smile is like a beacon of hope, illuminating the darkest of times.",
    "Your laughter is like a symphony, bringing harmony to the chaos of the world.",
    "Your friendship is like a warm ray of sunshine, brightening my day with joy and laughter.",
    "Your presence is like a gentle breeze, bringing peace and tranquility to my soul.",
    "Your wisdom is like a guiding star, illuminating my path through life's darkest nights.",
    "Your strength is like a mighty oak tree, standing tall and strong against the storms of life.",
    "Your courage is like a roaring lion, facing challenges with unwavering determination.",
    "Your compassion is like a gentle river, flowing with love and kindness for all beings.",
    "Your love is like a warm embrace, enveloping me in warmth and security.",
    "Your spirit is like a soaring eagle, reaching for the heavens with grace and majesty.",
    "Your determination is like a raging storm, unstoppable in the pursuit of your goals.",
    "Your resilience is like a diamond, unyielding and shining brightly in the face of adversity.",
    "Your adaptability is like a chameleon, blending seamlessly into any situation with ease and grace.",
    "Your humor is like a ray of sunshine, brightening the darkest of clouds with laughter and joy.",
    "Your creativity is like a kaleidoscope, transforming the ordinary into the extraordinary.",
    "Your imagination is like a limitless sky, soaring to new heights of wonder and possibility.",
    "Your intuition is like a whisper from the universe, guiding you towards the path of your true destiny.",
    "Your loyalty is like a steadfast rock, unwavering in the face of challenges and adversity.",
    "Your integrity is like a shining beacon, illuminating the path of truth and righteousness.",
    "Your courage is like a blazing fire, burning brightly in the face of fear and danger.",
    "Your strength is like a mighty river, flowing with unstoppable force towards your goals.",
    "Your beauty is like a blooming rose, captivating all who behold it with your grace and elegance.",
    "Your spirit is like a gentle breeze, carrying with it the fragrance of hope and renewal.",
    "Your mind is like a brilliant star, illuminating the darkness with your wisdom and knowledge.",
    "Your heart is like a pure spring, overflowing with love and compassion for all beings."
};

int main() {
    srand(time(NULL));

    int index = rand() % FORTUNES_COUNT;
    printf("Your fortune is: %s\n", fortunes[index]);

    return 0;
}